#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 6

typedef struct package

{
    char* id;
    int weight;
} 

package;

typedef struct post_office

{
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
} 

post_office;

typedef struct town

{
    char* name;
    post_office* offices;
    int offices_count;
} 

town;

town* find_town(town* towns, int towns_count, char* name)

{
    for (int i = 0; i < towns_count; i++)
    
    {
        if (strcmp(towns[i].name, name) == 0)
        
        {
            return &towns[i];
        }
    }
    return NULL;
}

void print_all_packages(town t)

{
    printf("%s:\n", t.name);
    for (int i = 0; i < t.offices_count; i++)
    
    {
        printf("\t%d:\n", i);
        for (int j = 0; j < t.offices[i].packages_count; j++)
        
        {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

town town_with_most_packages(town* towns, int towns_count)

{
    int max_packages = -1;
    town result;
    for (int i = 0; i < towns_count; i++)
    
    {
        int total = 0;
        for (int j = 0; j < towns[i].offices_count; j++)
        
        {
            total += towns[i].offices[j].packages_count;
        }
        
        if (total > max_packages)
        
        {
            max_packages = total;
            result = towns[i];
        }
    }
    return result;
}

void send_all_acceptable_packages(town* source, int source_index, town* target, int target_index)

{
    post_office* src = &source->offices[source_index];
    post_office* tgt = &target->offices[target_index];

    package* accepted = malloc(src->packages_count * sizeof(package));
    package* rejected = malloc(src->packages_count * sizeof(package));
    int acc_count = 0, rej_count = 0;

    for (int i = 0; i < src->packages_count; i++)
    
    {
        package p = src->packages[i];
        if (p.weight >= tgt->min_weight && p.weight <= tgt->max_weight)
        
        {
            accepted[acc_count].weight = p.weight;
            accepted[acc_count].id = malloc(strlen(p.id) + 1);
            strcpy(accepted[acc_count].id, p.id);
            acc_count++;
        } 
        
        else
        
        {
            rejected[rej_count].weight = p.weight;
            rejected[rej_count].id = malloc(strlen(p.id) + 1);
            strcpy(rejected[rej_count].id, p.id);
            rej_count++;
        }
        
        free(p.id);
    }

    free(src->packages);
    src->packages = rejected;
    src->packages_count = rej_count;

    tgt->packages = realloc(tgt->packages, sizeof(package) * (tgt->packages_count + acc_count));
    for (int i = 0; i < acc_count; i++)
    
    {
        tgt->packages[tgt->packages_count + i] = accepted[i];
    }
    
    tgt->packages_count += acc_count;
    free(accepted);
}

int main(void)

{
    int towns_count;
    scanf("%d", &towns_count);
    town* towns = malloc(sizeof(town) * towns_count);

    for (int i = 0; i < towns_count; i++)
    
    {
        towns[i].name = malloc(MAX_STRING_LENGTH);
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(post_office) * towns[i].offices_count);
        for (int j = 0; j < towns[i].offices_count; j++)
        
        {
            scanf("%d %d %d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(sizeof(package) * towns[i].offices[j].packages_count);
            for (int k = 0; k < towns[i].offices[j].packages_count; k++)
            
            {
                towns[i].offices[j].packages[k].id = malloc(MAX_STRING_LENGTH);
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }

    int queries;
    scanf("%d", &queries);
    char town_name[MAX_STRING_LENGTH];

    while (queries--)
    
    {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%s", town_name);
            town* t = find_town(towns, towns_count, town_name);
            print_all_packages(*t);
        } 
        
        else if (type == 2)
        
        {
            int source_index, target_index;
            town* source;
            town* target;
            scanf("%s", town_name);
            source = find_town(towns, towns_count, town_name);
            scanf("%d", &source_index);
            scanf("%s", town_name);
            target = find_town(towns, towns_count, town_name);
            scanf("%d", &target_index);
            send_all_acceptable_packages(source, source_index, target, target_index);
        } 
        
        else if (type == 3)
        
        {
            printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
        }
    }

    for (int i = 0; i < towns_count; i++)
    
    {
        for (int j = 0; j < towns[i].offices_count; j++) {
            for (int k = 0; k < towns[i].offices[j].packages_count; k++)
            
            {
                free(towns[i].offices[j].packages[k].id);
            }
            free(towns[i].offices[j].packages);
        }
        free(towns[i].offices);
        free(towns[i].name);
    }
    free(towns);
}