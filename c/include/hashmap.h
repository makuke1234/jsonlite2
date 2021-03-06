#ifndef HASHMAP_H
#define HASHMAP_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>

typedef struct hashNode
{
	char * key;
	void * value;

	struct hashNode * next;
} hashNode_t;

hashNode_t * hashNode_make(const char * key, void * value);
void hashNode_free(hashNode_t * restrict self);

void hashNode_recursiveFree(hashNode_t * restrict self);

typedef struct hashMap
{
	size_t numNodes;
	hashNode_t ** nodes;
} hashMap_t;

size_t hashMap_hash(const char * key, size_t mapSize);

bool hashMap_init(hashMap_t * restrict self, size_t minSize);
bool hashMap_resize(hashMap_t * restrict self, size_t minSize);

bool hashMap_insert(hashMap_t * restrict self, const char * key, void * value);
hashNode_t * hashMap_get(const hashMap_t * restrict self, const char * key);
void * hashMap_remove(hashMap_t * restrict self, const char * key);

void hashMap_destroy(hashMap_t * restrict self);

#ifdef __cplusplus
}
#endif

#endif
