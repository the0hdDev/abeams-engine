mkdir -p ./valgrind

BINARY=./cmake-build-debug/bin/abeams
OUTDIR=./valgrind

# 1. Memcheck (Memory leaks & UB)
valgrind \
  --tool=memcheck \
  --leak-check=full \
  --show-leak-kinds=all \
  --track-origins=yes \
  --undef-value-errors=yes \
  --num-callers=30 \
  --log-file=$OUTDIR/memcheck.log \
  $BINARY

# 2. Helgrind (Thread data races)
valgrind \
  --tool=helgrind \
  --log-file=$OUTDIR/helgrind.log \
  $BINARY

# 3. DRD (alternative Thread checking)
valgrind \
  --tool=drd \
  --log-file=$OUTDIR/drd.log \
  $BINARY

# 4. Callgrind (CPU profiling)
valgrind \
  --tool=callgrind \
  --callgrind-out-file=$OUTDIR/callgrind.out \
  $BINARY

# 5. Cachegrind (CPU cache profiling)
valgrind \
  --tool=cachegrind \
  --cachegrind-out-file=$OUTDIR/cachegrind.out \
  $BINARY

# 6. Massif (Heap profiling)
valgrind \
  --tool=massif \
  --massif-out-file=$OUTDIR/massif.out \
  $BINARY

# 7. DHAT (Detailed heap analysis)
valgrind \
  --tool=dhat \
  --log-file=$OUTDIR/dhat.log \
  $BINARY

# 8. FunC (Function call and memory tracking)
valgrind \
  --tool=funccheck \
  --log-file=$OUTDIR/funcc.log \
  $BINARY
