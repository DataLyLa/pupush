#include "push_swap.h"

void set_sa(t_count *count, int ra, int rra)
{
    if((ra - 1) < (rra + 1))
    {
        if (ra - 1 == - 1)
            count->rra = 1;
        else
        count->ra = ra - 1;
    }
    else
        count->rra = rra + 1;
    count->sa = 1;
    count->move = 1;
    count->total = count->ra + count->rra;
}

void set_ra_rra(t_count *count, int ra, int rra, char c)
{
    if(ra < rra)
        count->ra = ra;
    else
        count->rra = rra;
    if(c == 'b')
        count->pb = 1;
    else if(c == 'a')
        count->pa = 1;
    count->move = 2;
    count->total = count->ra + count->rra;
}

void set_rb_rrb(t_count *count, int rb, int rrb, char c)
{
    if(rb < rrb)
        count->rb = rb;
    else
        count->rrb = rrb;
    if(c == 'b')
        count->pb = 1;
    else if(c == 'a')
        count->pa = 1;
    count->move = 2;
    count->total = count->rb + count->rrb;
}


void set_rr(t_count *count, int ra, int rb, char c)
{
    if(ra < rb)
    {
        count->rb = rb - ra;
        count->rr = ra;
    }
    else
    {
        count->ra = ra - rb;
        count->rr = rb;
    }
    if(c == 'b')
        count->pb = 1;
    else if(c == 'a')
        count->pa = 1;
    count->move = 3;
    count->total = count->ra + count->rb + count->rr;
}

void set_rrr(t_count *count, int rra, int rrb, char c)
{
    if(rra < rrb)
    {
        count->rrb = rrb - rra;
        count->rrr = rra;
    }
    else
    {
        count->rra = rra - rrb;
        count->rrr = rrb;
    }
    if(c == 'b')
        count->pb = 1;
    else if(c == 'a')
        count->pa = 1;
    count->move = 4;
    count->total = count->rra + count->rrb + count->rrr;
}

