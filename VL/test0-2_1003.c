# include<stdio.h>
# include<string.h>
struct Rect
{
    int x;
    int y;
    int w;
    int h;
};
struct Rect cross;
int JudgeCross(struct Rect rect1, struct Rect rect2);
void CrossRect(struct Rect rect1, struct Rect rect2);
int main()
{
    struct Rect rect[100];
	int rectNum = 0, crossFlag = 0;
	char str[10000];
    scanf("%s", str);
    unsigned char temp[100];
    int temp_index = 0;
    memset(temp, '\0', sizeof(temp));
    int rect_temp[4];
    int rect_temp_index = 0;
    for (int i=0; i<=strlen(str); i++) {
        if (str[i]==',' || str[i]==';' || str[i]=='\0') {
            rect_temp[rect_temp_index++] = atoi(temp);
            memset(temp, '\0', sizeof(temp));
            temp_index = 0;
        }
        if (str[i]==';' || str[i]=='\0') {
            rect[rectNum].x = rect_temp[0];
            rect[rectNum].y = rect_temp[1];
            rect[rectNum].w = rect_temp[2];
            rect[rectNum].h = rect_temp[3];
            rectNum++;
            rect_temp_index = 0;
        } else if (str[i] == ',') {
            ;
        } else {
            temp[temp_index++] = str[i];
        }
    }

    if(rectNum == 1)
        printf("[%d,%d,%d,%d]  %d", rect[0].x,rect[0].y, rect[0].w, rect[0].h, rect[0].w*rect[0].h);
    else
    {
        for(int i = 0; i<rectNum-1; i++)
        {
            crossFlag = JudgeCross(rect[i], rect[i+1]);
            //printf("crossflag=%d\n", crossFlag);
            if(crossFlag == 0) break;
            CrossRect(rect[i], rect[i+1]);
        }
        if(crossFlag == 1)
        {
            //printf("[%d,%d,%d,%d]  %d\n", cross.x, cross.y, cross.w, cross.h, cross.w*cross.h);
            if(cross.w && cross.h) printf("[%d,%d,%d,%d]  %d\n", cross.x, cross.y, cross.w, cross.h, cross.w*cross.h);
        }
        else printf("Error\n");

    }
    
	
    return 0;
}

int JudgeCross(struct Rect rect1, struct Rect rect2)
{
    //printf("[%d,%d,%d,%d]  [%d,%d,%d,%d]\n", rect1.x, rect1.y, rect1.w, rect1.h, rect2.x, rect2.y, rect2.w, rect2.h);
    if(rect1.x + rect1.w <= rect2.x || rect2.x + rect2.w <= rect1.x || rect1.y - rect1.h >= rect2.y || rect2.y - rect2.h >= rect1. y)
        return 0;
    else 
        return 1;
}

void CrossRect(struct Rect rect1, struct Rect rect2)
{
    //printf("[%d,%d,%d,%d]  [%d,%d,%d,%d]\n", rect1.x, rect1.y, rect1.w, rect1.h, rect2.x, rect2.y, rect2.w, rect2.h);
    if(rect1.x > rect2.x) cross.x = rect1.x;
    else cross.x = rect2.x;

    if(rect1.y < rect2.y) cross.y = rect1.y;
    else cross.y = rect2.y;

    if(rect1.x + rect1.w < rect2.x + rect2.w) cross.w = rect1.x + rect1.w;
    else cross.w = rect2.x + rect2.w;

    if(rect1.y - rect1.h > rect2.y - rect2.h) cross.h = rect1.y - rect1.h;
    else cross.h = rect2.y - rect2.h;

    cross.w = cross.w - cross.x;
    cross.h = cross.y - cross.h;
}