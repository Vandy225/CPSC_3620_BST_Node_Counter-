#ifndef DICTIONARY_H
#define DICTIONARY_H
// The Dictionary abstract class.
template <typename Key, typename E>

   class Dictionary {
  private:
   void operator =(const Dictionary&) {}
   Dictionary(const Dictionary&) {}
  public:
   Dictionary() {} // Default constructor
   virtual ~Dictionary() {} // Base destructor
// Reinitialize dictionary
   virtual void clear() = 0;
// Insert a record
// k: The key for the record being inserted.
// e: The record being inserted.
   virtual void insert(const Key& k, const E& e) = 0;
   virtual int size() = 0;
};

#endif
