#ifndef LOGSTRUCTURE_H_INCLUDED
#define LOGSTRUCTURE_H_INCLUDED

using namespace std;

struct nodeLogChanges
{
    string searchedWord;
    string replacementWord;
    bool isChanged;
    string palabra;
    int position;
    struct nodeLogChanges *next;
};

nodeLogChanges *firstChanges = new nodeLogChanges();
nodeLogChanges *firstReverts = new nodeLogChanges();
nodeLogChanges *previous = new nodeLogChanges();
nodeLogChanges *sentinelChanges = new nodeLogChanges();
nodeLogChanges *popNode = new nodeLogChanges();

void addChangeNode(nodeLogChanges *logChange)
{
    sentinelChanges = logChange;

    if(firstChanges == NULL)
    {
        firstChanges = logChange;
    }
    else while (sentinelChanges != NULL)
    {
        if(sentinelChanges->next == NULL)
        {
            sentinelChanges->next = logChange;
            break;
        }

        sentinelChanges = sentinelChanges->next;
    }
}

void addRevertNode(nodeLogChanges *logChange)
{
    sentinelChanges = logChange;

    if(firstReverts == NULL)
    {
        firstReverts = logChange;
    }
    else while (sentinelChanges != NULL)
    {
        if(sentinelChanges->next == NULL)
        {
            sentinelChanges->next = logChange;
            break;
        }

        sentinelChanges = sentinelChanges->next;
    }
}

nodeLogChanges popChangeNode()
{
    sentinelChanges = firstChanges;

    if(firstChanges == NULL)
    {
        cout << "The Heap is empty" << endl;
    }
    else while (sentinelChanges != NULL)
    {
        if(firstChanges->next == NULL)
        {
            popNode = firstChanges;
            firstChanges = NULL;
            return *popNode;
        }
        else
        {
            previous = sentinelChanges;
            sentinelChanges = sentinelChanges->next;

            if(sentinelChanges->next == NULL)
            {
                popNode = sentinelChanges;
                previous->next = NULL;
                sentinelChanges = NULL;
                return *popNode;
            }
        }
    }
}

void popRevertNode()
{
    sentinelChanges = firstReverts;

    if(firstReverts == NULL)
    {
        cout << "The Heap is empty" << endl;
    }
    else while (sentinelChanges != NULL)
    {
        if(firstReverts->next == NULL)
        {
            firstReverts = NULL;
            break;
        }
        else
        {
            previous = sentinelChanges;
            sentinelChanges = sentinelChanges->next;

            if(sentinelChanges->next == NULL)
            {
                previous->next = NULL;
                sentinelChanges = NULL;
                break;
            }
        }
    }
}

#endif // LOGSTRUCTURE_H_INCLUDED

