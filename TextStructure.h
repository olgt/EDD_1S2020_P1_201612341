#ifndef TEXTSTRUCTURE_H_INCLUDED
#define TEXTSTRUCTURE_H_INCLUDED

using namespace std;

struct nodeChar
{
    char character;
    struct nodeChar *next;
    struct nodeChar *previous;
};

static nodeChar *firstChar = new nodeChar();
static nodeChar *previousChar = new nodeChar();
static nodeChar *sentinelCharacter = new nodeChar();
static nodeChar *sentinelCharacterReplaceWord = new nodeChar();
static nodeChar *searchedWord = new nodeChar();
static nodeChar *sentinelSearchedWord = new nodeChar();

static nodeChar *replaceWord = new nodeChar();
static nodeChar *lastNodeReplaceWord = new nodeChar();

void addCharacterNode(nodeChar *newCharacter)
{
    sentinelCharacter = firstChar;

    if(firstChar == NULL || firstChar->character == NULL)
    {
        firstChar = newCharacter;
        firstChar->next = NULL;
    }
    else
    {
        sentinelCharacter = firstChar;

        while(sentinelCharacter != NULL)
        {
            if(sentinelCharacter->next == NULL)
            {
                newCharacter->previous = sentinelCharacter;
                sentinelCharacter->next = newCharacter;
                break;
            }
            else
            {
                sentinelCharacter = sentinelCharacter->next;
            }
        }
    }
}

void deleteLastNode()
{
    sentinelCharacter = firstChar;

    if(firstChar == NULL || firstChar->character == NULL)
    {
        //Nada
    }
    else if(firstChar->next == NULL)
    {
        firstChar = NULL;
    }
    else
    {
        sentinelCharacter = firstChar;

        while(sentinelCharacter != NULL)
        {
            if(sentinelCharacter->next == NULL)
            {
                sentinelCharacter->previous->next = NULL;
                sentinelCharacter->previous = NULL;
                sentinelCharacter = NULL;
                break;
            }
            else
            {
                sentinelCharacter = sentinelCharacter->next;
            }
        }
    }
}

void addCharacterNodeSearchedWord(nodeChar *newCharacter)
{
    sentinelCharacter = searchedWord;

    if(searchedWord == NULL || searchedWord->character == NULL)
    {
        searchedWord = newCharacter;
        searchedWord->next = NULL;
    }
    else
    {
        sentinelCharacter = searchedWord;

        while(sentinelCharacter != NULL)
        {
            if(sentinelCharacter->next == NULL)
            {
                newCharacter->previous = sentinelCharacter;
                sentinelCharacter->next = newCharacter;
                break;
            }
            else
            {
                sentinelCharacter = sentinelCharacter->next;
            }
        }
    }
}

void deleteLastNodeSearchedWord()
{
    sentinelCharacter = searchedWord;

    if(searchedWord == NULL || searchedWord->character == NULL)
    {
        //Nada
    }
    else if(searchedWord->next == NULL)
    {
        searchedWord = NULL;
    }
    else
    {
        sentinelCharacter = searchedWord;

        while(sentinelCharacter != NULL)
        {
            if(sentinelCharacter->next == NULL)
            {
                sentinelCharacter->previous->next = NULL;
                sentinelCharacter->previous = NULL;
                sentinelCharacter = NULL;
                break;
            }
            else
            {
                sentinelCharacter = sentinelCharacter->next;
            }
        }
    }
}


void addCharacterNodeReplaceWord(nodeChar *newCharacter)
{
    nodeChar *sentinelCharacter3 = new nodeChar();
    sentinelCharacter3 = replaceWord;

    if(replaceWord == NULL || replaceWord->character == NULL)
    {
        replaceWord = newCharacter;
        replaceWord->next = NULL;
    }
    else
    {
        sentinelCharacter3 = replaceWord;

        while(sentinelCharacter3 != NULL)
        {
            if(sentinelCharacter3->next == NULL)
            {
                newCharacter->previous = sentinelCharacter3;
                sentinelCharacter3->next = newCharacter;
                break;
            }
            else
            {
                sentinelCharacter3 = sentinelCharacter3->next;
            }
        }
    }
}

void deleteLastNodeReplaceWord()
{
    sentinelCharacter = replaceWord;

    if(replaceWord == NULL || replaceWord->character == NULL)
    {
        //Nada
    }
    else if(replaceWord->next == NULL)
    {
        replaceWord = NULL;
    }
    else
    {
        sentinelCharacter = replaceWord;

        while(sentinelCharacter != NULL)
        {
            if(sentinelCharacter->next == NULL)
            {
                sentinelCharacter->previous->next = NULL;
                sentinelCharacter->previous = NULL;
                sentinelCharacter = NULL;
                break;
            }
            else
            {
                sentinelCharacter = sentinelCharacter->next;
            }
        }
    }
}

void assignLasNodeOfReplaceWord()
{
    nodeChar *sentinelReplaceWord = new nodeChar();
    sentinelReplaceWord = replaceWord;

    while(sentinelReplaceWord->next != NULL)
    {
        sentinelReplaceWord = sentinelReplaceWord->next;
    }

    lastNodeReplaceWord = sentinelReplaceWord;
}

#endif // TEXTSTRUCTURE_H_INCLUDED
