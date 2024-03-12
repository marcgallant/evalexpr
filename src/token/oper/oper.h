#ifndef OPER_H
#define OPER_H

typedef int (*bin_op)(int, int, int *);

enum associativity
{
    LEFT,
    RIGHT,
    OPEN,
    CLOSE
};

struct oper
{
    int prec;
    enum associativity ass;
    bin_op func;
};
/**
 * \brief Add the two integer together
 *
 * \param a First integer
 * \param b Second integer
 * \param err Error parameter
 * \return The addition of the two integers
 */
int my_add(int a, int b, int *err);

/**
 * \brief Subtract the two integer together
 *
 * \param a First integer
 * \param b Second integer
 * \param err Error parameter
 * \return The subtraction of the two integers
 */
int my_sub(int a, int b, int *err);

/**
 * \brief Multiply the two integer together
 *
 * \param a First integer
 * \param b Second integer
 * \param err Error parameter
 * \return The multiplication of the two integers
 */
int my_mul(int a, int b, int *err);

/**
 * \brief Divide the two integer together
 *
 * \param a First integer
 * \param b Second integer
 * \param err Error parameter set at 3 on division by 0
 * \return The division of the two integers
 */
int my_div(int a, int b, int *err);

/**
 * \brief Modulo of the two integer together
 *
 * \param a First integer
 * \param b Second integer
 * \param err Error parameter set at 3 on modulo by 0
 * \return The modulo of the two integers
 */
int my_mod(int a, int b, int *err);

/**
 * \brief Power of the two integer together
 *
 * \param a First integer
 * \param b Second integer
 * \param err Error parameter set at 3 on power by 0 or less
 * \return The power of the two integers
 */
int my_pow(int a, int b, int *err);

/**
 * \brief Initialize a operator
 *
 * \param c Character representing the operator
 * \param rpn Boolean describing the expression type
 * \param err Error parameter set to 1 on lexing error
 * \return The operator
 */
struct oper oper_init(char c, int rpn, int *err);

#endif /* ! OPER_H */
