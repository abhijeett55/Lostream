# 🧠 Performance Analysis of Memory Allocators

## 1. Allocation Performance Comparison

| **Allocator Type** | **Avg Time per Op (ms)** | **Ops per ms** | **Memory Efficiency** |
|--------------------|--------------------------|----------------|-----------------------|
| **C (Default)**    | 0–24.7                   | ∞–0.04         | Poor (0 bytes peak)   |
| **Linear**         | 21.3–24.7                | 0.04–0.047     | Poor (0 bytes peak)   |
| **Stack**          | 24.4–38.9                | 0.026–0.041    | Good                  |
| **Pool**           | **1.6**                  | **0.625**      | **Excellent**         |

---

## 2. Key Observations

### 🏆 **Pool Allocator**
The clear performance winner:

- **16× faster** than Stack Allocator  
- **15× faster** than Linear Allocator  
- Ideal for **fixed-size allocations**  
- **Consistent** performance regardless of allocation size  

### 🧱 **Stack Allocator**
- Provides **good memory tracking**  
- Follows **LIFO (Last-In-First-Out)** pattern during free operations  
- Shows **moderate performance**  

### ⚙️ **C/Library Allocator**
- Shows **0 ms** times (likely due to a measurement issue)  
- Does **not track memory peaks**  

---

## 3. Allocation Performance (ms/operation)
### Allocation Speed (Lower is Better)

| Allocator | Avg Time (ms) |
|------------|---------------|
| **Pool** | **1.6 ms** |
| **Linear** | 23.4 ms |
| **Stack** | 28.9 ms |
| **C Library** | 22.1 ms* |

> *Note: The C library allocator timing may include measurement anomalies.*

---


## 🏗️ Allocator Types

### 1. Pool Allocator ⭐ **BEST PERFORMANCE**
- **Speed**: 1.6ms per operation (16x faster than others)
- **Use Case**: Fixed-size object allocations
- **Advantage**: Pre-allocated memory blocks, minimal overhead
- **Limitation**: Fixed block sizes

### 2. Stack Allocator
- **Speed**: 24.4-38.9ms per operation
- **Use Case**: LIFO allocation patterns
- **Advantage**: Good memory locality
- **Feature**: Proper memory tracking and padding calculation

### 3. Linear Allocator
- **Speed**: 21.3-24.7ms per operation  
- **Use Case**: Temporary, sequential allocations
- **Advantage**: Simple implementation
- **Limitation**: No individual deallocation

### 4. C Standard Library
- **Speed**: Variable (0-24.7ms)
- **Use Case**: General purpose
- **Note**: Shows inconsistent timing measurements

## 📈 Memory Efficiency

| Allocator | Peak Memory Usage | Memory Tracking |
|-----------|------------------|-----------------|
| Pool      | 40,960 bytes     | ✅ Excellent    |
| Stack     | 41,040 bytes     | ✅ Good         |
| Linear    | 0 bytes*         | ❌ None         |
| C Library | 0 bytes*         | ❌ None         |

*\*Likely due to implementation issues in benchmarking*

## 🔧 Technical Details

### Benchmark Parameters
- **Block Sizes**: 32, 64, 256, 512, 1024, 2048, 4096 bytes
- **Alignment**: 8 bytes
- **Operations**: 10 allocations per test
- **Tests**: Pure allocation + allocation/free cycles

### Stack Allocator Behavior
- Shows proper LIFO deallocation pattern
- Padding calculation: consistent 8-byte alignment
- Memory offset tracking: visible in debug output

### Pool Allocator Advantage
- Direct block assignment without searching
- No fragmentation overhead
- Constant-time allocations

## 🚀 Recommendations

1. **Use Pool Allocator** for:
   - Game object pools
   - Particle systems
   - Network packet buffers
   - Any fixed-size frequent allocations

2. **Use Stack Allocator** for:
   - Frame-based allocations
   - Temporary scratch memory
   - State machine contexts

3. **Use Linear Allocator** for:
   - Loading phases
   - Bulk data processing
   - Temporary work buffers

## 📁 Project Structure

src/
├── Allocator.hpp # Base allocator interface
├── LinearAllocator.hpp # Sequential allocator
├── StackAllocator.hpp # LIFO allocator
├── PoolAllocator.hpp # Fixed-block allocator
├── FreeListAllocator.hpp # Free list implementation
└── Benchmark.cpp # Performance tests


---

## 🛠️ Building

```bash
# Configure
cmake -B build

# Build
cmake --build build

# Run benchmarks
./build/Debug/main.exe


---



## Key Insights from Your Data:

1. **Pool allocator is 15-20x faster** than other allocators
2. **Stack allocator shows proper memory management** with visible padding and offset tracking
3. **C library allocator benchmarks may have measurement issues** (showing 0ms)
4. **Memory peak tracking works correctly** for Stack and Pool allocators
5. **Free operations** properly follow LIFO pattern in Stack allocator

The README provides a comprehensive overview that would be valuable for anyone evaluating memory allocator performance for their projects.
