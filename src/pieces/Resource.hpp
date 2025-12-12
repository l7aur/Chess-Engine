#pragma once

#include <filesystem>

class Resource {
public:
    inline static const std::filesystem::path WHITE_PATH_TO_PAWN = "resources/white_pawn.png";
    inline static const std::filesystem::path BLACK_PATH_TO_PAWN = "resources/black_pawn.png";

    inline static const std::filesystem::path WHITE_PATH_TO_ROOK = "resources/white_rook.png";
    inline static const std::filesystem::path BLACK_PATH_TO_ROOK = "resources/black_rook.png";

    inline static const std::filesystem::path WHITE_PATH_TO_KNIGHT = "resources/white_knight.png";
    inline static const std::filesystem::path BLACK_PATH_TO_KNIGHT = "resources/black_knight.png";

    inline static const std::filesystem::path WHITE_PATH_TO_BISHOP = "resources/white_bishop.png";
    inline static const std::filesystem::path BLACK_PATH_TO_BISHOP = "resources/black_bishop.png";

    inline static const std::filesystem::path WHITE_PATH_TO_QUEEN = "resources/white_queen.png";
    inline static const std::filesystem::path BLACK_PATH_TO_QUEEN = "resources/black_queen.png";

    inline static const std::filesystem::path WHITE_PATH_TO_KING = "resources/white_king.png";
    inline static const std::filesystem::path BLACK_PATH_TO_KING = "resources/black_king.png";
};