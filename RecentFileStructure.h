#ifndef RECENTFILESTRUCTURE_H_INCLUDED
#define RECENTFILESTRUCTURE_H_INCLUDED

using namespace std;

struct nodeRecentFiles
{
    string name;
    string path;
    struct nodeRecentFiles *next;

};

nodeRecentFiles *firstRecent = NULL;
nodeRecentFiles *previousRecent = NULL;
nodeRecentFiles *sentinelRecent = NULL;

void addRecentFileNode(nodeRecentFiles *newFile)
{
    sentinelRecent = newFile;

    if(firstRecent == NULL)
    {
        firstRecent = newFile;
        firstRecent->next = firstRecent;
    }
    else while (sentinelRecent != firstRecent)
    {
        if(sentinelRecent->next = firstRecent)
        {
            sentinelRecent->next = newFile;
            newFile->next = firstRecent;
            break;
        }

        sentinelRecent = sentinelRecent->next;
    }
}

#endif // RECENTFILESTRUCTURE_H_INCLUDED
