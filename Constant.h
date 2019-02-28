#ifndef CONSTANT_H_INCLUDED
#define CONSTANT_H_INCLUDED

const char QUIT = 'q';
const char HELP = 'h';

const char DOT = '.';

const char ADDITION = '+';   const char SUBTRACTION = '-';
const char MULTIPLY = '*';   const char DIVISION = '/';
const char POWER = '^';      const char PERCENTAGE = '%';
const char EQUAL = '=';      const char REVERSE = 'r';

const char SIN = 's'; const char ARCSIN = 'S';
const char COS = 'c'; const char ARCCOS = 'C';
const char TAN = 't'; const char ARCTAN = 'T';
const char DEG = 'D'; const char RAD = 'R';

const char M = 'M';
const char MADD = 'x';
const char MMIN = 'v';
const char MCLEAR = 'C';

const char AC = 'A';
const char C = 'C';

/**  STATE */
const int MOP = 0;
const int MCIRCLE = 1;
const int MRAD = 2;

const int OP_ADD = 0;
const int OP_MIN = 1;
const int OP_MUL = 2;
const int OP_DIV = 3;
const int OP_POW = 4;

const int CIR_DF = 0;
const int CIR_SIN = 1;  const int CIR_ASIN = -1;
const int CIR_COS = 2;  const int CIR_ACOS = -2;
const int CIR_TAN = 3;  const int CIR_ATAN = -3;


/**  MODE  */
const int NOR = 0;   const char FUNCTION = 'f';
const int MEM = 1;   const char MEMORY = 'm';

#endif // CONSTANT_H_INCLUDED
