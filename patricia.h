/*
 * patricia.h
 * Patricia trie implementation.
 */

#ifndef _PATRICIA_H_
#define _PATRICIA_H_

/*
 * Patricia tree mask.
 * Each node in the tree can contain multiple masks, so this
 * structure is where the mask and data are kept.
 */
struct ptree_mask {
  unsigned long pm_mask;
  void *pm_data;
};

/*
 * Patricia tree node.
 */
struct ptree {
  unsigned long p_key;    /* Node key     */
  struct ptree_mask *p_m; /* Node masks       */
  unsigned char p_mlen;   /* Number of masks  */
  char p_b;               /* Bit to check     */
  struct ptree *p_left;   /* Left pointer     */
  struct ptree *p_right;  /* Right pointer    */
};

extern struct ptree *pat_insert(struct ptree *n, struct ptree *head);
extern int pat_remove(struct ptree *n, struct ptree *head);
extern struct ptree *pat_search(unsigned long key, struct ptree *head);
extern int pat_count(struct ptree *t, int b);

#endif /* _PATRICIA_H_ */
