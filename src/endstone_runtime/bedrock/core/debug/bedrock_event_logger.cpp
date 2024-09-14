// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "bedrock/core/debug/bedrock_event_logger.h"

#include <cstdio>

#include <magic_enum/magic_enum.hpp>

#include "bedrock/diagnostics/log_level.h"
#include "endstone/detail/logger_factory.h"
#include "endstone/logger.h"

void BedrockLog::log_va(LogCategory /*category*/, std::bitset<3> /*channel_mask*/, LogRule /*rule*/, LogAreaID area,
                        std::uint32_t priority, const char * /*function*/, int /*line*/, const char *format,
                        va_list args)
{
    auto name = magic_enum::enum_name(area);
    auto &logger = endstone::detail::LoggerFactory::getLogger(std::string(name));
    endstone::Logger::Level log_level;
    switch (priority) {
    case Bedrock::LogLevel::Verbose:
        log_level = endstone::Logger::Level::Debug;
        break;
    case Bedrock::LogLevel::Info:
        log_level = endstone::Logger::Level::Info;
        break;
    case Bedrock::LogLevel::Warning:
        log_level = endstone::Logger::Level::Warning;
        break;
    case Bedrock::LogLevel::Error:
        log_level = endstone::Logger::Level::Error;
        break;
    default:
        log_level = endstone::Logger::Level::Critical;
        break;
    }

    std::va_list args_copy;
    va_copy(args_copy, args);
    std::vector<char> buf(1 + std::vsnprintf(nullptr, 0, format, args));
    va_end(args);
    std::size_t len = std::vsnprintf(buf.data(), buf.size(), format, args_copy);
    va_end(args_copy);

    std::string message(buf.data(), len);
    message.erase(message.find_last_not_of(" \t\n\r\f\v") + 1);

    std::size_t start = 0;
    std::size_t end;

    while ((end = message.find('\n', start)) != std::string::npos) {
        logger.log(log_level, message.substr(start, end - start));
        start = end + 1;
    }

    if (start < message.length()) {
        logger.log(log_level, message.substr(start));
    }
}
