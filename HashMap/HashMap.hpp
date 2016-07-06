#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#define kHASHSIZE 1024
// forward declearation
template <typename KEY, typename VALUE>
class HashMap;
template <typename KEY, typename VALUE>
class Node {
 public:
  KEY getKey() const;
  VALUE getValue() const;

 private:
  friend class HashMap<KEY, VALUE>;
  Node() : next(NULL), key(), value() {}
  Node(const KEY &k, const VALUE &v) : key(k), value(v), next(NULL) {}
  // cascade deletion
  ~Node() {
    if (next) delete next;
  }
  KEY key;
  VALUE value;
  Node *next;
};
template <typename KEY, typename VALUE>
class HashMap {
 public:
  /**
    * defalut constructor
    */
  HashMap();
  /**
   * constructor using a vector of pairs
   * @param pairs a vector contains all the key-value pairs
   * @note duplicate keys in the vector leads to undefined behavior
   */
  HashMap(const std::vector<std::pair<KEY, VALUE> > &t_pairs);
  /**
   * constructor using a list of pairs
   * @param pairs a list contains all the key-value pairs
   * @note duplicate keys in the list leads to undefined behavior
   */
  HashMap(const std::list<std::pair<KEY, VALUE> > &t_pairs);
  /**
   * copy constructor
   * @param t_another another HashMap
   */
  HashMap(const HashMap &t_another);
  /**
   * destructor
   */
  ~HashMap();
  /**
   * assignment operator overloaded
   * @param t_another another HashMap
   */
  HashMap &operator=(const HashMap &t_another);
  /**
   * get current size
   * @return the size of this map
   */
  int size(void) const;
  /**
   * check the map is empty or not
   * @return if empty, true will be return
   */
  bool empty(void) const;
  /**
   * get current size
   * @param t_key key, the key
   * @param t_value value, the value
   * @note duplicate keys in the vector leads to a replace behavior
   */
  void insert(const KEY &t_key, const VALUE &t_value);
  /**
   * find if a key is in the map
   * @return if the map has the key, return true
   */
  bool has(const KEY &t_key) const;
  /**
   * remove a pair from the map
   * @return if success, return true
   */
  bool erase(const KEY &t_key);
  /**
   * remove all the paris in the map
   */
  void clear();
  /**
   * get all the keys
   * @return a vector of keys
   */
  std::vector<KEY> keys(void) const;
  /**
   * get all the values
   * @return a vector of values
   */
  std::vector<VALUE> values(void) const;
  /**
   * get all the pairs
   * @return a vector of pairs
   */
  std::vector<std::pair<KEY, VALUE> > items(void) const;
  /**
   * access a value using key-index
   * @param t_key a key
   * @return the refernce of the value
   * @note if the key is not in the map, a new pair will
              be created implicitly using the given key
   */
  VALUE &operator[](const KEY &t_key);

 private:
  // hash function
  // inline unsigned long long HashValue(const KEY & t_key) const {
  //   return reinterpret_cast<unsigned long long>(key);
  // }
  unsigned int HashValue(const KEY &t_key) const;
  inline Node<KEY, VALUE> *find(const KEY &key) {
    unsigned long long hv = HashValue(key);
    int p = hv % kHASHSIZE;
    for (Node<KEY, VALUE> *ptr = m_heads[p]; ptr->next; ptr = ptr->next)
      if (ptr->next->key == key) return ptr->next;
    return NULL;
  }
  std::vector<Node<KEY, VALUE> *> m_heads;
  int m_size;
};
// #include "HashMap.cc"
#endif  // HASHMAP_HPP
