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

#pragma once

#include "bedrock/bedrock.h"
#include "bedrock/forward.h"
#include "bedrock/util/biome_tag_registry_types.h"

class WellKnownTagID {
public:
    BiomeTagID tag_id;
    BiomeTagRegistry *tag_registry;
};

struct WellKnownBiomeTags {
    WellKnownTagID MONSTER_TAG_ID;
    WellKnownTagID ANIMAL_TAG_ID;
    WellKnownTagID OCEAN_TAG_ID;
    WellKnownTagID NETHER_TAG_ID;
    WellKnownTagID END_TAG_ID;
    WellKnownTagID MOOSHROOM_TAG_ID;
    WellKnownTagID PLAINS_TAG_ID;
    WellKnownTagID DESERT_TAG_ID;
    WellKnownTagID JUNGLE_TAG_ID;
    WellKnownTagID BAMBOO_JUNGLE_TAG_ID;
    WellKnownTagID TAIGA_TAG_ID;
    WellKnownTagID EXTREME_HILLS_TAG_ID;
    WellKnownTagID SAVANNA_TAG_ID;
    WellKnownTagID FROZEN_TAG_ID;
    WellKnownTagID COLD_TAG_ID;
    WellKnownTagID LUKEWARM_TAG_ID;
    WellKnownTagID WARM_TAG_ID;
    WellKnownTagID RIVER_TAG_ID;
    WellKnownTagID SWAMP_TAG_ID;
    WellKnownTagID BEACH_TAG_ID;
    WellKnownTagID FLOWER_FOREST_TAG_ID;
    WellKnownTagID FOREST_TAG_ID;
    WellKnownTagID BIRCH_TAG_ID;
    WellKnownTagID HILLS_TAG_ID;
    WellKnownTagID MUTATED_TAG_ID;
    WellKnownTagID EDGE_TAG_ID;
    WellKnownTagID PLATEAU_TAG_ID;
    WellKnownTagID DEEP_TAG_ID;
    WellKnownTagID MESA_TAG_ID;
    WellKnownTagID ICE_PLAINS_TAG_ID;
    WellKnownTagID ICE_TAG_ID;
    WellKnownTagID MOUNTAIN_TAG_ID;
    WellKnownTagID SHORE_TAG_ID;
    WellKnownTagID STONE_TAG_ID;
    WellKnownTagID ROOFED_TAG_ID;
    WellKnownTagID MEGA_TAG_ID;
    WellKnownTagID RARE_TAG_ID;
    WellKnownTagID NO_LEGACY_WORLDGEN_TAG_ID;
    WellKnownTagID OVERWORLD_TAG_ID;
    WellKnownTagID OVERWORLD_GEN_TAG_ID;
    WellKnownTagID FOREST_GEN_TAG_ID;
};
BEDROCK_STATIC_ASSERT_SIZE(WellKnownBiomeTags, 984, 984);
