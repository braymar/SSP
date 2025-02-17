#pragma once


// Generated automatically by TheTechnobear
// derived from EigenD scale manager
// open source : https://github.com/EigenLabs/EigenD

// scale is dim(bit11) to root (bit 0), e.g. b#a#g#fe#d#c



static const struct Scales {
    char name[30];
    uint16_t numnotes;
    uint16_t scale;
} scales[MAX_SCALES] = {
    {"chromatic", 12,0b111111111111},
    {"major", 7,0b101010110101},
    {"minor", 7,0b010110101101},
    {"ionian", 7,0b101010110101},
    {"locrian", 7,0b010101101011},
    {"phrygian", 7,0b010110101011},
    {"aeolian", 7,0b010110101101},
    {"dorian", 7,0b011010101101},
    {"mixolydian", 7,0b011010110101},
    {"lydian", 7,0b101011010101},

    {"blues", 6,0b010011101001},
    {"flamenco", 8,0b010110111011},
    {"spanish", 7,0b010110110011},
    {"indian", 7,0b010110011011},
    {"persian", 7,0b100101110011},
    {"oriental", 7,0b011001110011},
    {"gypsy", 7,0b100110110011},
    {"arabian", 7,0b100110110011},
    {"hindu", 7,0b010110110101},
    {"ethiopian", 7,0b100110110101},
    {"japanese", 5,0b000110100011},
    {"hirajoshi", 5,0b000110001101},
    {"algerian", 7,0b100111001101},
    {"romanian", 7,0b011011001101},
    {"pentatonic major", 5,0b001010010101},
    {"egyptian", 7,0b100111001101},
    {"pentatonic minor", 5,0b010010101001},

    {"hungarian minor", 7,0b100111001101},
    {"spanish 8 tone", 8,0b010101111011},
    {"symmetrical", 8,0b011011011011},
    {"inverted diminished", 8,0b011011011011},
    {"diminished", 8,0b101101101101},
    {"whole tone", 6,0b010101010101},
    {"augmented", 6,0b100110011001},
    {"3 semitone", 4,0b001001001001},
    {"4 semitone", 3,0b000100010001},
    {"locrian ultra", 7,0b001101011011},
    {"locrian super", 7,0b010101011011},
    {"neapolitan minor", 7,0b100110101011},
    {"javanese", 7,0b011010101011},
    {"neapolitan major", 7,0b101010101011},
    {"todi", 7,0b100111001011},
    {"phrygian major", 7,0b010110110011},
    {"jewish", 7,0b010110110011},
    {"double harmonic", 7,0b100110110011},
    {"byzantine", 7,0b100110110011},
    {"chahargah", 7,0b100110110011},
    {"marva", 7,0b101011010011},
    {"enigmatic", 7,0b110101010011},
    {"locrian natural", 7,0b010101101101},
    {"natural minor", 7,0b010110101101},
    {"melodic minor", 7,0b101010101101},
    {"harmonic minor",  7,0b100110101101},
    {"algerian 2", 7,0b010110101101},
    {"algerian 1", 7,0b100111001101},
    {"mohammedan", 7,0b100110101101},
    {"hungarian gypsy", 7,0b100111001101},
    {"locrian major", 7,0b010101110101},
    {"mixolydian augmented", 7,0b011100110101},
    {"harmonic major", 7,0b101100110101},
    {"lydian minor", 7,0b010111010101},
    {"lydian dominant", 7,0b011011010101},
    {"overtone", 7,0b011011010101},
    {"lydian augmented", 7,0b011101010101},
    {"leading whole tone", 7,0b110101010101},
    {"hungarian major", 7,0b011011011001},
    {"pb", 5,0b000101001011},
    {"balinese", 5,0b000110001011},
    {"pe", 5,0b000110001011},
    {"pelog", 5,0b010010001011},
    {"iwato", 5,0b010001100011},
    {"kumoi", 5,0b000110100011},
    {"pa", 5,0b000110001101},
    {"pd", 5,0b001010001101},
    {"chinese", 5,0b001010010101},
    {"chinese 1", 5,0b001010010101},
    {"mongolian", 5,0b001010010101},
    {"pfcg", 5,0b001010010101},
    {"chinese 2", 5,0b100011010001},
    {"altered", 7,0b010101011011},
    {"bebop dominant", 8,0b111010110101},
    {"bebop dominant flatnine", 8,0b111010110011},
    {"bebop major", 8,0b101110110101},
    {"bebop minor", 8,0b011110101101},
    {"bebop tonic minor", 8,0b101110101101},
    {"natural major", 7,0b101010110101},
    {"monotone", 0,0b000000000001}
};

