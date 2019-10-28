#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <array>

// We need the DBGameAssets and CoDAssetType classes
#include "DBGameAssets.h"
#include "CoDAssetType.h"

// Handles reading from Modern Warfare 3
class GameModernWarfare3
{
public:
    // -- Game functions

    // Loads offsets for Modern Warfare 3
    static bool LoadOffsets();
    // Loads assets for Modern Warfare 3
    static bool LoadAssets();

    // Reads an XAnim from Modern Warfare 3
    static std::unique_ptr<XAnim_t> ReadXAnim(const CoDAnim_t* Animation);
    // Reads a XModel from Modern Warfare 3
    static std::unique_ptr<XModel_t> ReadXModel(const CoDModel_t* Model);

    // Reads an XImageDDS from a image reference from Modern Warfare 3
    static std::unique_ptr<XImageDDS> LoadXImage(const XImage_t& Image);

    // Reads a string via it's string index for Modern Warfare 3
    static std::string LoadStringEntry(uint64_t Index);

private:
    // -- Game offsets databases

    // A list of offsets for Modern Warfare 3 single player
    static std::array<DBGameInfo, 2> SinglePlayerOffsets;
    // A list of offsets for Modern Warfare 3 multi player
    static std::array<DBGameInfo, 2> MultiPlayerOffsets;

    // -- Game utilities

    // Reads an XMaterial from it's logical offset in memory
    static const XMaterial_t ReadXMaterial(uint64_t MaterialPointer);
};