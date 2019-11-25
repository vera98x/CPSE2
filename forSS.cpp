for (int rounds = 0; rounds < 10; rounds++) {
        std::cout << "timing for sensorbuffer map: \n";

        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 500; j++) {
                bufferMap[names[i]][bufferIndexMap] = result;
                bufferIndexMap++;
            }
            bufferIndexMap = 0;
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        std::cout << "elapsed time: " << ((end.tv_sec - start.tv_sec) + 1e-9 * (end.tv_nsec - start.tv_nsec)) << "\n";
}
