#ifndef CACHE_BLOCK_H
#define CACHE_BLOCK_H

#include <string>
#include <vector>

    class CacheBlock{
    private:
        std::string data[4];
        bool valid = false;
        bool dirty = false;
        int tag;

    public:
        bool isValid();
        void setValid(bool valid);

        bool isDirty();
        void setDirty(bool dirty);

        int getTag();
        void setTag(int tag);

        std::string getData(int offset);
        void setData(std::string data, int offset);

        std::vector<std::string> toVector();

    };

#endif