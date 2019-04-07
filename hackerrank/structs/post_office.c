#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
    printf("%s:\n", t.name);
    for(int officeNum = 0; officeNum < t.offices_count; officeNum ++){
        printf("\t%d:\n", officeNum);
        post_office o = *(t.offices + officeNum);

        for(int pkg=0; pkg < o.packages_count; pkg++){
            package p = *(o.packages + pkg);
            printf("\t\t%s\n", p.id);
        }

    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    post_office source_office = *((*source).offices + source_office_index);
    post_office target_office = *((*target).offices + target_office_index);

    // Determine how many packages move
    int moving_packages = 0;
    for(int spkg = 0; spkg < source_office.packages_count; spkg++){
        if(source_office.packages[spkg].weight <= target_office.max_weight &&
           source_office.packages[spkg].weight >= target_office.min_weight) {
            moving_packages++;
        }
    }

    // Expand the target package list to accommodate those packages that are moving
    package* ptr = malloc((target_office.packages_count + moving_packages) * sizeof(package));
    for(int i=0; i< target_office.packages_count; i++){
        ptr[i] = target_office.packages[i];
    }
    target_office.packages = ptr;

    // Conversely, create a new queue at the source that contains fewer packages.
    // This isn't strictly necessary
    package* new_source_queue = malloc((source_office.packages_count - moving_packages) * sizeof(package));

    // move Add the target packages to the tail of the target office,
    // and shrink the source office's queue accordingly
    for(int i=0,
            si=0,
            ti=target_office.packages_count;
            i< source_office.packages_count; i++){

        package source_package = source_office.packages[i];

        if(source_package.weight <= target_office.max_weight &&
           source_package.weight >= target_office.min_weight) {
            target_office.packages[ti++] = source_package;
        } else {
            new_source_queue[si++] = source_package;
        }

    }

    source_office.packages = new_source_queue;
    target_office.packages_count += moving_packages;
    source_office.packages_count -= moving_packages;

    target->offices[target_office_index] = target_office;
    source->offices[source_office_index] = source_office;

}

int packages_count(town t) {
    int i=0;
    for(int o=0; o< t.offices_count; o++){
        i+= t.offices[o].packages_count;
    }
    return i;
}

town town_with_most_packages(town* towns, int towns_count) {
    int max_pkgs=0;
    for(int i=0; i< towns_count; i++){
        if (packages_count(towns[i]) > packages_count(towns[max_pkgs])){
            max_pkgs = i;
        }
    }

    return towns[max_pkgs];
}

town* find_town(town* towns, int towns_count, char* name) {
    for(int i=0; i< towns_count; i++){
        char* town_name = (*(towns + i)).name;
        if(strcmp(name, town_name) == 0){
            return (towns+i);
        }
    }
    return towns;
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
