#include "PieceConfig.hpp"

unsigned int PieceConfig::NUMBER_OF_PIECES_PER_SET(const Type type) {
    switch (type)
    {
    case ROOK:
        [[fallthrough]];
    case KNIGHT:
        [[fallthrough]];
    case BISHOP:
        return 2;
    case QUEEN:
        [[fallthrough]];
    case KING:
        return 1;
    default:
        return 8;
    }
    return 0;
};

std::filesystem::path PieceConfig::PATH_TO_SPRITE(const Type type, const PieceColor color) {
    return color == PieceColor::White
        ? WHITE_PATH_TO_SPRITE(type)
        : BLACK_PATH_TO_SPRITE(type);
}

std::filesystem::path PieceConfig::WHITE_PATH_TO_SPRITE(const Type type) {
    switch (type)
    {
    case ROOK:
        return "resources/white_rook.png";
    case KNIGHT:
        return "resources/white_knight.png";
    case BISHOP:
        return "resources/white_bishop.png";
    case QUEEN:
        return "resources/white_queen.png";
    case KING:
        return "resources/white_king.png";
    default:
        return "resources/white_pawn.png";
    }
    return "";
}

std::filesystem::path PieceConfig::BLACK_PATH_TO_SPRITE(const Type type) {
    switch (type)
    {
    case ROOK:
        return "resources/black_rook.png";
    case KNIGHT:
        return "resources/black_knight.png";
    case BISHOP:
        return "resources/black_bishop.png";
    case QUEEN:
        return "resources/black_queen.png";
    case KING:
        return "resources/black_king.png";
    default:
        return "resources/black_pawn.png";
    }
    return "";
}

std::list<Position> PieceConfig::POSITIONS(const Type type, const PieceColor color) {
    switch (type)
    {
    case ROOK:
        return color == PieceColor::White ? WhiteRooksPositions() : BlackRooksPositions();
    case KNIGHT:
        return color == PieceColor::White ? WhiteKnightsPositions() : BlackKnightsPositions();
    case BISHOP:
        return color == PieceColor::White ? WhiteBishopsPositions() : BlackBishopsPositions();
    case QUEEN:
        return color == PieceColor::White ? WhiteQueensPositions() : BlackQueensPositions();
    case KING:
        return color == PieceColor::White ?  WhiteKingsPositions() : BlackKingsPositions();
    default:
        return color == PieceColor::White ? WhitePawnsPositions() : BlackPawnPositions();
    }
    return {};
}

std::list<Position> PieceConfig::WhitePawnsPositions() {
    return {
        Position{1, 0},
        Position{1, 1},
        Position{1, 2},
        Position{1, 3},
        Position{1, 4},
        Position{1, 5},
        Position{1, 6},
        Position{1, 7}
    };
}

std::list<Position> PieceConfig::BlackPawnPositions() {
    return {
        Position{6, 0},
        Position{6, 1},
        Position{6, 2},
        Position{6, 3},
        Position{6, 4},
        Position{6, 5},
        Position{6, 6},
        Position{6, 7}
    };
}

std::list<Position> PieceConfig::WhiteRooksPositions() {
    return {
        Position{0, 0},
        Position{0, 7}
    };
}

std::list<Position> PieceConfig::BlackRooksPositions() {
    return {
        Position{7, 0},
        Position{7, 7}
    };
}

std::list<Position> PieceConfig::WhiteKnightsPositions() {
    return {
        Position{0, 1},
        Position{0, 6}
    };
}

std::list<Position> PieceConfig::BlackKnightsPositions() {
    return {
        Position{7, 1},
        Position{7, 6}
    };
}

std::list<Position> PieceConfig::WhiteBishopsPositions() {
    return {
        Position{0, 2},
        Position{0, 5}
    };
}

std::list<Position> PieceConfig::BlackBishopsPositions() {
    return {
        Position{7, 2},
        Position{7, 5}
    };
}

std::list<Position> PieceConfig::WhiteQueensPositions() {
    return { Position{0, 3} };
}

std::list<Position> PieceConfig::BlackQueensPositions() {
    return { Position{7, 3} };
}

std::list<Position> PieceConfig::WhiteKingsPositions() {
    return { Position{0, 4} };
}

std::list<Position> PieceConfig::BlackKingsPositions() {
    return { Position{7, 4} };
}