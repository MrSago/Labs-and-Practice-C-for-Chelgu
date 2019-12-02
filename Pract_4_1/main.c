#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char* KeyType;
typedef char* ValueType;

typedef struct __TreeNode {

	KeyType key;
	ValueType value;
	struct __TreeNode* left;
	struct __TreeNode* right;

} TreeNode, * Tree;

TreeNode* CreateAndInitTreeNode(KeyType key, ValueType value);
bool InsertTreeValueByKey(Tree* root, KeyType key, ValueType value);
bool InsertTreeNode(Tree* root, TreeNode* newNode);
TreeNode* SearchValueByKey(Tree root, KeyType key);
ValueType GetValueByKey(Tree root, KeyType key);
void PostOrderTreeRemove(Tree root);
void ClearTree(Tree* root);

char* readline();
char** split_string(char* str);


TreeNode* CreateAndInitTreeNode(KeyType key, ValueType value) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

	node->key = key;
	node->value = value;
	node->left = NULL;
	node->right = NULL;

	return node;
}

bool InsertTreeValueByKey(Tree* root, KeyType key, ValueType value) {
	TreeNode* node = CreateAndInitTreeNode(key, value);
	return InsertTreeNode(root, node);
}

bool InsertTreeNode(Tree* root, TreeNode* newNode) {
	if (*root == NULL) {
		*root = newNode;
		return true;
	}

	TreeNode* tmp = *root;

	while (tmp != NULL) {
		if (strcmp(newNode->key, tmp->key) > 0) {
			if (tmp->right == NULL) {
				tmp->right = newNode;
				tmp = NULL;
			}
			else {
				tmp = tmp->right;
			}
		}
		else if (strcmp(newNode->key, tmp->key) < 0) {
			if (tmp->left == NULL) {
				tmp->left = newNode;
				tmp = NULL;
			}
			else {
				tmp = tmp->left;
			}
		}
		else {
			return false;
		}
	}

	return true;
}

TreeNode* SearchValueByKey(Tree root, KeyType key) {
	if (root == NULL) {
		return NULL;
	}

	TreeNode* tmp = root;

	while (tmp != NULL) {
		if (strcmp(key, tmp->key) > 0) {
			tmp = tmp->right;
		}
		else if (strcmp(key, tmp->key) < 0) {
			tmp = tmp->left;
		}
		else {
			return tmp;
		}
	}

	return NULL;
}

ValueType GetValueByKey(Tree root, KeyType key) {
	if (root == NULL) {
		return NULL;
	}

	TreeNode* node = SearchValueByKey(root, key);

	if (node == NULL) {
		return NULL;
	}
	else {
		return node->value;
	}
}

void PostOrderTreeRemove(Tree root) {
	if (root == NULL) {
		return;
	}

	PostOrderTreeRemove(root->left);
	PostOrderTreeRemove(root->right);
	free(root->key);
	free(root);
}

void ClearTree(Tree* root) {
	PostOrderTreeRemove(*root);
	return;
}

char* readline() {
	size_t alloc_length = 1024;
	size_t data_length = 0;
	char* data = malloc(alloc_length);

	while (1) {
		char* cursor = data + data_length;
		char* line = fgets(cursor, (int)(alloc_length - data_length), stdin);

		if (!line) { break; }

		data_length += strlen(cursor);

		if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

		size_t new_length = alloc_length << 1;
		data = realloc(data, new_length);

		if (!data) { break; }

		alloc_length = new_length;
	}

	if (data[data_length - 1] == '\n') {
		data[data_length - 1] = '\0';
	}

	data = realloc(data, data_length);

	return data;
}

char** split_string(char* str) {
	char** splits = NULL;
	char* token = strtok(str, " ");

	int spaces = 0;

	while (token) {
		splits = realloc(splits, sizeof(char*) * ++spaces);
		if (!splits) {
			return splits;
		}

		splits[spaces - 1] = token;

		token = strtok(NULL, " ");
	}

	return splits;
}


int main() {
	char* n_endptr;
	char* n_str = readline();
	int n = strtol(n_str, &n_endptr, 10);

	if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

	Tree root = NULL;

	for (int i = 0; i < n; ++i) {
		char** arr_tmp = split_string(readline());
		InsertTreeValueByKey(&root, (KeyType)arr_tmp[0], (ValueType)arr_tmp[1]);
		free(arr_tmp);
	}

	char** search_keys = NULL;
	int c, k = 0;
	while ((c = fgetc(stdin)) != EOF) {
		ungetc(c, stdin);
		search_keys = realloc(search_keys, sizeof(char*) * ++k);
		search_keys[k - 1] = readline();
	}

	for (int i = 0; i < n; ++i) {
		char* value = (char*)GetValueByKey(root, (KeyType)search_keys[i]);

		if (value) {
			printf("%s=%s\n", search_keys[i], value);
		}
		else {
			printf("Not found\n");
		}

		free(search_keys[i]);
	}

	free(n_str);
	free(search_keys);
	ClearTree(&root);

	return 0;
}
