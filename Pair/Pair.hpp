template <typename T, typename G>

class Pair
{
   public:
    T key;
    G value;
    Pair() = default;
    Pair(const T& key, const G& value) : key(key), value(value) {};

    friend std::ostream& operator<<(std::ostream& os, const Pair& pair) {
        os << "{" << pair.key << ", " << pair.value << "}";
        return os;
    }
};