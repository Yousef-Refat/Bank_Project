#pragma once

#include <iostream>
#include <limits>
#include <vector>
#include <fstream>

using namespace std;

class clsString
{
private:
    string _Text;

    static short ReadValidateShortInRange(string Message, short From, short To)
    {
        short Number;
        cout << Message;
        cin >> Number;
        while ((!(Number >= From && Number <= To)) || cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Invalid Number\n";
            cout << Message;
            cin >> Number;
        }
        return Number;
    }

public:
    clsString(string Text)
    {
        _Text = Text;
    }

    clsString()
    {
        _Text = "";
    }

    static string ReadString(string Message = "Please enter a text\n", bool IgnoreEnterPress = 1, bool FirstInLoop = 0)
    {
        string St;
        cout << Message;
        if (FirstInLoop && IgnoreEnterPress)
        {
            cin.ignore(1, '\n');
            getline(cin >> ws, St);
            return St;
        }
        if (FirstInLoop)
        {
            getline(cin >> ws, St);
            return St;
        }
        if (IgnoreEnterPress)
        {
            cin.ignore(1, '\n');
            getline(cin, St);
        }
        else
        {
            getline(cin, St);
        }
        return St;
    }

    enum enWhatToCount
    {
        SmallLetters = 1,
        CapitalLetters = 2,
        Digitt = 3,
        Punctuation = 4,
        All = 5
    };

    static enWhatToCount ReadWhatToCount(string Message = "Please enter what you want to count \n1: Small Letters\n2: CapitalLetters\n3: Digits\n4: Punctuation\n5: All  ")
    {
        return (enWhatToCount)ReadValidateShortInRange(Message, 1, 5);
    }

    static char InvertLetterCase(char X)
    {
        // return isupper(char1) ? tolower(char1) : toupper(char1);
        if (islower(X))
        {
            return toupper(X);
        }
        else if (isupper(X))
        {
            return tolower(X);
        }
        else
        {
            return X;
        }
    }

    static string InvertAllLettersCase(string Text)
    {
        for (short i = 0; i < Text.length(); i++)
        {
            Text[i] = InvertLetterCase(Text[i]);
        }
        return Text;
    }

    void InvertAllLettersCase()
    {
        _Text = InvertAllLettersCase(_Text);
    }

    static vector<string> Split(string Text, string Sperator = " ")
    {
        vector<string> vContent;
        short Pos = 0;
        string sWord;
        while ((Pos = Text.find(Sperator)) != std::string::npos)
        {
            sWord = Text.substr(0, Pos);
            if (sWord != "")
            {
                vContent.push_back(sWord);
            }
            Text.erase(0, Pos + Sperator.length());
        }
        if (Text != "")
        {
            vContent.push_back(Text);
        }
        return vContent;
    }

    void SetString(string Text)
    {
        _Text = Text;
    }

    string GetString()
    {
        return _Text;
    }

    static string LowerAllString(string Text)
    {
        for (short i = 0; i <= Text.length() - 1; i++)
        {
            Text[i] = tolower(Text[i]);
        }
        return Text;
    }

    void LowerAll()
    {
        _Text = LowerAllString(_Text);
    }

    static string UpperAllString(string Text)
    {
        for (short i = 0; i <= Text.length() - 1; i++)
        {
            Text[i] = toupper(Text[i]);
        }
        return Text;
    }

    void UpperAllString()
    {
        _Text = UpperAllString(_Text);
    }

    static short CountLetters(string Text, enWhatToCount WhatToCount = enWhatToCount::All)
    {
        if (WhatToCount == enWhatToCount::All)
        {
            return Text.length();
        }
        short Counter = 0;
        for (short i = 0; i <= Text.length() - 1; i++)
        {
            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(Text[i]))
            {
                Counter++;
            }
            if (WhatToCount == enWhatToCount::SmallLetters && islower(Text[i]))
            {
                Counter++;
            }
            if (WhatToCount == enWhatToCount::Digitt && isdigit(Text[i]))
            {
                Counter++;
            }
            if (WhatToCount == enWhatToCount::Punctuation && ispunct(Text[i]))
            {
                Counter++;
            }
        }
        return Counter;
    }

    short CountLetters(enWhatToCount WhatToCount = enWhatToCount::All)
    {
        return CountLetters(_Text, WhatToCount);
    }

    static short CountSpecificLetter(string Text, char Character, bool MatchCase = true)
    {
        short Counter = 0;
        for (short i = 0; i <= Text.length() - 1; i++)
        {
            if (MatchCase)
            {
                if (Text[i] == Character)
                {
                    Counter++;
                }
            }
            else
            {
                if (tolower(Text[i]) == tolower(Character))
                {
                    Counter++;
                }
            }
        }
        return Counter;
    }

    short CountSpecificLetter(char Character, bool MatchCase = true)
    {
        return CountSpecificLetter(_Text, Character, MatchCase);
    }

    static string RemovePunctuations(string Text)
    {
        string S2 = "";
        for (short i = 0; i < Text.length(); i++)
        {
            if (!ispunct(Text[i]))
            {
                S2 += Text[i];
            }
        }
        return S2;
    }

    void RemovePunctuations()
    {
        _Text = RemovePunctuations(_Text);
    }

    static bool IsVowel(char Ch)
    {
        Ch = tolower(Ch);

        return ((Ch == 'a') || (Ch == 'e') || (Ch == 'i') || (Ch == 'o') || (Ch == 'u'));
    }

    static short CountVowels(string Text)
    {
        short Counter = 0;
        for (short i = 0; i < Text.length(); i++)
        {
            if (IsVowel(Text[i]))
                Counter++;
        }

        return Counter;
    }

    short CountVowels()
    {
        return CountVowels(_Text);
    }

    static string TrimLeft(string Text)
    {
        for (short i = 0; i < Text.length(); i++)
        {
            if (Text[i] != ' ')
            {
                return Text.substr(i, Text.length() - i);
            }
        }
        return "";
    }

    void TrimLeft()
    {
        _Text = TrimLeft(_Text);
    }

    static string TrimRight(string Text)
    {
        for (short i = Text.length() - 1; i >= 0; i--)
        {
            if (Text[i] != ' ')
            {
                return Text.substr(0, i + 1);
            }
        }
        return "";
    }

    void TrimRight()
    {
        _Text = TrimRight(_Text);
    }

    static string Trim(string Text)
    {
        return (TrimLeft(TrimRight(Text)));
    }

    void Trim()
    {
        _Text = Trim(_Text);
    }

    static string ReverseWords(string Text, string Sperator = " ")
    {
        vector<string> vString = Split(Text, Sperator);
        string Text2 = "";
        vector<string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {
            iter--;
            Text2 += *iter + Sperator;
        }
        Text2 = Text2.substr(0, Text2.length() - Sperator.length());
        return Text2;
    }

    string ReverseWords(string Sperator = " ")
    {
        return ReverseWords(_Text, Sperator);
    }

    static string ReplaceWordByBuiltInFunction(string Text, string ReplaceFrom, string RepalceTo)
    {
        short Pos;
        while ((Pos = Text.find(ReplaceFrom)) != std::string::npos)
        {
            Text = Text.replace(Pos, ReplaceFrom.length(), RepalceTo);
        }
        return Text;
    }

    string ReplaceWordByBuiltInFunction(string ReplaceFrom, string RepalceTo)
    {
        return ReplaceWordByBuiltInFunction(_Text, ReplaceFrom, RepalceTo);
    }

    static string JoinString(vector<string> vString, string Sperator)
    {
        string S1 = "";
        for (string &s : vString)
        {
            S1 = S1 + s + Sperator;
        }
        return S1.substr(0, S1.length() - Sperator.length());
    }

    static string JoinString(string ArrString[], short Length, string Sperator)
    {
        string S1 = "";
        for (short i = 0; i < Length; i++)
        {
            S1 = S1 + ArrString[i] + Sperator;
        }
        return S1.substr(0, S1.length() - Sperator.length());
    }

    static string ReplaceWord(string Text, string ReplaceFrom, string RepalceTo, bool MatchCase = true)
    {
        vector<string> vString = Split(Text, " ");
        for (string &s : vString)
        {
            if (MatchCase)
            {
                if (s == ReplaceFrom)
                {
                    s = RepalceTo;
                }
            }
            else
            {
                if (LowerAllString(s) == LowerAllString(ReplaceFrom))
                {
                    s = RepalceTo;
                }
            }
        }
        return JoinString(vString, " ");
    }

    string ReplaceWord(string ReplaceFrom, string RepalceTo)
    {
        return ReplaceWord(_Text, ReplaceFrom, RepalceTo);
    }

    static short CountWords(string Text)
    {

        string Sperator = " ";
        short Counter = 0;
        short Pos = 0;
        string sWord;

        while ((Pos = Text.find(Sperator)) != std::string::npos)
        {
            sWord = Text.substr(0, Pos);
            if (sWord != "")
            {
                Counter++;
            }
            Text.erase(0, Pos + Sperator.length());
        }

        if (Text != "")
        {
            Counter++;
        }

        return Counter;
    }

    short CountWords()
    {
        return CountWords(_Text);
    };

    static short Length(string Text)
    {
        return Text.length();
    };

    short Length()
    {
        return _Text.length();
    };

    static string UpperFirstLetterOfEachWord(string Text)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < Text.length(); i++)
        {
            if (Text[i] != ' ' && isFirstLetter)
            {
                Text[i] = toupper(Text[i]);
            }
            isFirstLetter = (Text[i] == ' ' ? true : false);
        }
        return Text;
    }

    void UpperFirstLetterOfEachWord()
    {
        _Text = UpperFirstLetterOfEachWord(_Text);
    }

    static string LowerFirstLetterOfEachWord(string Text)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < Text.length(); i++)
        {
            if (Text[i] != ' ' && isFirstLetter)
            {
                Text[i] = tolower(Text[i]);
            }
            isFirstLetter = (Text[i] == ' ' ? true : false);
        }
        return Text;
    }

    void LowerFirstLetterOfEachWord()
    {
        _Text = LowerFirstLetterOfEachWord(_Text);
    }

    static short CountCapitalLetters(string Text)
    {
        short Counter = 0;
        for (short i = 0; i < Text.length(); i++)
        {
            if (isupper(Text[i]))
                Counter++;
        }
        return Counter;
    }

    short CountCapitalLetters()
    {
        return CountCapitalLetters(_Text);
    }

    static short CountSmallLetters(string Text)
    {
        short Counter = 0;
        for (short i = 0; i < Text.length(); i++)
        {
            if (islower(Text[i]))
                Counter++;
        }
        return Counter;
    }

    short CountSmallLetters()
    {
        return CountSmallLetters(_Text);
    }
};