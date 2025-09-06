#include "PoolAllocator.hpp"
#include <cassert>
#include <stdlib.h>
#include <algorithm>
#ifdef _DEBUG
#include <iostream>
#endif


PoolAllocator::PoolAllocator(const std::size_t totalSize, const std::size_t chunkSize) : PoolAllocator(totalSize)  {
    assert(chunkSize >= 8 && "Chunk size must be greater or equal to 8");
    assert(totalSize % chunkSize == 0 && "Total Sized must be a multiple of Chunk size");
    this->m_chunkSize  = chunkSize;
}


void PoolAllocator::Init() {
    m_start_ptr = malloc(m_totalSize);
    this->Reset();
}

PoolAllocator::~PoolAllocator() {
    free(m_start_ptr);
}


void *PoolAllocator::Allocate(const std::size_t allocationSize, const std::size_t alignment) {
    assert(allocationSize == this->m_chunkSize && "Allocation size must be equal to chunk size");

    Node *freePosition = m_freeList.pop();

    assert(freePosition != nullptr && "the pool allocator is full");

    m_used += m_chunkSize;

    m_peak = std::max(m_peak, m_used);
    #ifdef _DEBUG
    std::cout <<"A" <<"\t@S" << m_start_ptr << "\t@R " << (void*) freePosition << "\tM "<<m_used <<std::endl;
    #endif

    return (void* ) freePosition;
}

void PoolAllocator::Free(void* ptr) {
    m_used -= m_chunkSize;

    m_freeList.push((Node *) ptr);


    #ifdef DEBUG_
    std::cout<<"F" <<"\t@S "<< m_start_ptr <<"\t@F "<< ptr <<"\tM "<< m_used <<std::endl;
    #endif
}

void PoolAllocator::Reset() {
    m_used = 0;
    m_peak = 0

    const int nChunks = m_totalSize / m_chunkSize;
    for(int i= 0; i < nChunks; i++) {
        std::size_t address = (std::size_t ) m_start_ptr + i * m_chunkSize;
        m_freeList.push(Node *) address;
    }
}