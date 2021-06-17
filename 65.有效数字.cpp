/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * 有限状态自动机
 * 
 * [65] 有效数字
 */

// @lc code=start
class Solution
{
public:
    enum State
    {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END
    };
    enum CharType
    {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_ILLEGAL
    };
    CharType toCharType(char c)
    {
        if (c >= '0' && c <= '9')
            return CHAR_NUMBER;
        else if (c == 'e' || c == 'E')
            return CHAR_EXP;
        else if (c == '.')
            return CHAR_POINT;
        else if (c == '+' || c == '-')
            return CHAR_SIGN;
        else
            return CHAR_ILLEGAL;
    }

    bool isNumber(string s)
    {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {STATE_INITIAL,
             {{CHAR_NUMBER, STATE_INTEGER},
              {CHAR_SIGN, STATE_INT_SIGN},
              {CHAR_POINT, STATE_POINT_WITHOUT_INT}}},
            {STATE_INT_SIGN,
             {{CHAR_POINT, STATE_POINT_WITHOUT_INT},
              {CHAR_NUMBER, STATE_INTEGER}}},
            {STATE_INTEGER,
             {{CHAR_NUMBER, STATE_INTEGER},
              {CHAR_EXP, STATE_EXP},
              {CHAR_POINT, STATE_POINT}}},
            {STATE_POINT,
             {{CHAR_NUMBER, STATE_FRACTION},
              {CHAR_EXP, STATE_EXP}}},
            {STATE_POINT_WITHOUT_INT,
             {{CHAR_NUMBER, STATE_FRACTION}}},
            {STATE_FRACTION,
             {{CHAR_NUMBER, STATE_FRACTION},
              {CHAR_EXP, STATE_EXP}}},
            {STATE_EXP,
             {{CHAR_SIGN, STATE_EXP_SIGN},
              {CHAR_NUMBER, STATE_EXP_NUMBER}}},
            {STATE_EXP_SIGN,
             {{CHAR_NUMBER, STATE_EXP_NUMBER}}},
            {STATE_EXP_NUMBER,
             {{CHAR_NUMBER, STATE_EXP_NUMBER}}}};
        int len = s.length();
        State st = STATE_INITIAL;
        for (int i = 0; i < len; ++i)
        {
            CharType tp = toCharType(s[i]);
            if (tp == CHAR_ILLEGAL || transfer[st].count(tp) == 0)
                return false;
            else
                st = transfer[st][tp];
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER;
    }
};
// @lc code=end
