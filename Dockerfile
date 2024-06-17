FROM python:3.12-slim-bullseye as base

LABEL maintainer="Endstone <hello@endstone.dev>"

ENV PYTHONUNBUFFERED=1 \
    PYTHONIOENCODING=UTF-8

FROM base AS builder

ARG LLVM_VERSION=15

RUN apt-get update -y -qq \
    && apt-get install -y -qq build-essential lsb-release wget software-properties-common gnupg \
    && wget https://apt.llvm.org/llvm.sh \
    && chmod +x llvm.sh \
    && ./llvm.sh ${LLVM_VERSION} \
    && apt-get install -y -qq libc++-${LLVM_VERSION}-dev libc++abi-${LLVM_VERSION}-dev \
    && update-alternatives --install /usr/bin/cc cc /usr/bin/clang-${LLVM_VERSION} 100 \
    && update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++-${LLVM_VERSION} 100 \
    && update-alternatives --install /usr/bin/llvm-cov llvm-cov /usr/bin/llvm-cov-${LLVM_VERSION} 100 \
    && update-alternatives --install /usr/bin/ld ld /usr/bin/ld.lld-${LLVM_VERSION} 100

ARG CMAKE_VERSION=3.26.6

ARG CMAKE_SH=cmake-${CMAKE_VERSION}-linux-x86_64.sh

RUN apt-get update -y -qq \
    && apt-get install -y -qq wget \
    && wget https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/${CMAKE_SH} \
    && chmod +x ${CMAKE_SH} \
    && ./${CMAKE_SH} --skip-license --exclude-subdir --prefix=/usr/local

RUN apt-get update -y -qq \
    && apt-get install -y -qq git ninja-build

WORKDIR /usr/src/endstone

RUN git clone https://github.com/EndstoneMC/endstone.git .

RUN python -m pip install --upgrade pip \
    && pip install wheel auditwheel setuptools "patchelf>=0.14" pytest \
    && python -m pip wheel . --no-deps --wheel-dir=wheelhouse --verbose \
    && python -m auditwheel --verbose repair --plat manylinux_2_31_x86_64 -w dist wheelhouse/*.whl \
    && pip install dist/*-manylinux_2_31_x86_64.whl \
    && pytest python/tests

FROM base AS final

RUN apt-get update -y -qq \
    && apt-get install -y -qq curl \
    && apt-get clean -y -qq \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -m -s /bin/bash endstone \
    && printf "endstone:endstone" | chpasswd \
    && adduser endstone sudo \
    && printf "endstone ALL= NOPASSWD: ALL\\n" >> /etc/sudoers

WORKDIR /home/endstone

COPY --from=builder /usr/src/endstone/dist .

RUN python -m pip install --upgrade pip \
    && pip install ./*-manylinux_2_31_x86_64.whl \
    && rm ./*.whl

USER endstone

EXPOSE 19132/udp 19133/udp

CMD ["endstone"]
