#include <iostream>
#include "val.h"
using namespace std;

Value Value::operator-(const Value &op) const
{
    if (GetType() == op.GetType())
    {
        if (IsInt())
            return Value(Itemp - op.GetInt());

        else if (IsReal())
            return Value(Rtemp - op.GetReal());

        else
            return Value();
    }

    else if (IsInt() && op.IsReal())
        return Value((float)Itemp - op.GetReal());

    else if (IsReal() && op.IsInt())
        return Value(Rtemp - (float)op.GetInt());

    else
        return Value();
}

Value Value::operator*(const Value &op) const
{
    if (GetType() == op.GetType())
    {
        if (IsInt())
            return Value(Itemp * op.GetInt());

        else if (IsReal())
            return Value(Rtemp * op.GetReal());

        else
            return Value();
    }

    else if (IsInt() && op.IsReal())
        return Value((float)Itemp * op.GetReal());

    else if (IsReal() && op.IsInt())
        return Value(Rtemp * (float)op.GetInt());

    else
        return Value();
}

Value Value::operator<(const Value &op) const
{
    if (GetType() == op.GetType())
    {
        if (IsInt())
            return Value(Itemp < op.GetInt());

        else if (IsReal())
            return Value(Rtemp < op.GetReal());

        else if (IsString())
            return Value();

        else if (IsBool())
            return Value(Btemp < op.GetBool());

        else
            return Value();
    }

    else if (IsInt() && op.IsReal())
        return Value((float)Itemp < op.GetReal());

    else if (IsReal() && op.IsInt())
        return Value(Rtemp < (float)op.GetInt());

    else
        return Value();
}

Value Value::operator&&(const Value &op) const
{
    if (GetType() == op.GetType())
    {
        if (IsBool())
            return Value(Btemp && op.GetBool());

        else
            return Value();
    }

    else
        return Value();
}