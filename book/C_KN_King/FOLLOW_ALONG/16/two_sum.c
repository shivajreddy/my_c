#include <stdio.h>
#include <uthash.h>

typedef struct HashItem
{
    int key;           // can be named anything, can be of any type
    int index;         // can be named anything, can be of any type
    UT_hash_handle hh; // must be named hh, must be of type UT_hash_handle
} HashItem;

void clean_hash_table(struct HashItem *hash)
{
    struct HashItem *current, *temp;
    HASH_ITER(hh, hash, current, temp)
    {
        HASH_DEL(hash, current);
        free(current);
    }
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = malloc(2 * sizeof(int));
    *returnSize = 2;

    // Create a hashmap
    struct HashItem *map = NULL;

    for (int i = 0; i < numsSize; i++) {
        int compliment = target - nums[i];

        // Check if compliment is alread visited
        struct HashItem *hash_item = malloc(sizeof(HashItem));
        HASH_FIND_INT(map, &compliment, hash_item);

        // Already Visited
        if (hash_item != NULL) {
            result[0] = hash_item->index;
            result[1] = i;
            clean_hash_table(map);
            return result;
        }

        // Not Visited, add to map, to mark as visited
        hash_item->key = nums[i];
        hash_item->index = i;
        HASH_ADD_INT(map, key, hash_item);
    }

    result[0] = -1;
    result[1] = -1;
    clean_hash_table(map);
    return result;
}

int *twoSum_heap(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = malloc(2 * sizeof(int)); // Allocate space for 2 integers
    *returnSize = 2;                       // mark the size of allocated memory

    // Create a hashmap
    HashItem *visited = NULL;

    for (int i = 0; i < numsSize; i++) {
        // Get compilement
        int compliment = target - nums[i];

        HashItem *hash_item;
        HASH_FIND_INT(visited, &compliment, hash_item);

        // Already visited
        if (hash_item != NULL) {
            result[0] = hash_item->index;
            result[1] = i;

            // Clean up hash table
            clean_hash_table(visited);
            return result;
        }
        // Add current number & its index to hashmap
        struct HashItem *new_item = malloc(sizeof(HashItem));
        new_item->key = nums[i];
        new_item->index = i;

        HASH_ADD_INT(visited, key, new_item);
    }

    // No match found
    clean_hash_table(visited);
    result[0] = -1;
    result[1] = -1;
    return result;
}

int main() {}
