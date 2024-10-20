#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

auto start = high_resolution_clock::now();

// For some set of integers a < b <= k, where k is the maximal limit, 
// find the maximum base ten decimal value of a binary XOR operation 
// between a and b for a given low, high, and max set of integers...

int main()
{

    const int N = 3, M = 2, L = 8;

    int      ii     = 0;
    int       F     = 0;
    int       U     = 0;

    double       nV = 2.0;
    double        S = 0.0;
    double   ANSWER = 0.0;   

    double     V[M] = { 1.0, 0.0 };
    double     A[N] = { 0.0, 0.0, 0.0 };
    double   LIM[M] = { 0.0, 0.0 };
    double  COMP[M] = { 0.0, 0.0 };    
  

    double    B[L], T[L], XOR[L];

    double    G[N][L];

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 255.0);


    while (N) {

        for (int i = 0; i <= N - 1; i++) {

            A[i] = int(dist(mt));
        }

        if ((A[0] < A[1] && A[0] < A[2]) && (A[1] > A[2] || A[1] <= A[2])) {

            if (A[1] <= A[2]) {

                LIM[0] = A[1] - 1;

                F = 0; U = 1;
            }
            else if (A[1] > A[2]) {

                LIM[1] = A[2];

                F = 1; U = 2;
            }

            for (int i = 0; i <= N - 1; i++) {

                std::cout << A[i] << std::endl;
            }
            std::cout << "\n";

            break;
        }
    }

    for (int i = L - 1; i >= 0; i--) {

        B[ii] = -i; ii++;
    }

    for (int i = 0; i <= L - 1; i++) {

        B[i] = pow(nV, B[i]);
    }

    for (int j = 0; j <= N - 1; j++) {

        S = A[j] + 0.5;

        for (int i = 0; i <= L - 1; i++) {

            G[j][i] = int(S * B[i]);

            G[j][i] = (G[j][i] - int(G[j][i] / nV) * nV) + 1;

            if (G[j][i] <= 1) {

                G[j][i] = 0;
            }
            else if(G[j][i] > 1 ) {

                G[j][i] = 1;
            }
            std::cout << G[j][i] << std::endl;
        }
        std::cout << "\n";
    }

    // XOR

    for (int j = A[0]; j <= LIM[F]; j++) {

        if (F == 0 || F == 1) {

            S = double(j) + 0.5;

            for (int i = 0; i <= L - 1; i++) {

                T[i] = int(S * B[i]);

                T[i] = (T[i] - int(T[i] / nV) * nV) + 1;

                if (T[i] <= 1) {

                    T[i] = 0;
                }
                else if (T[i] > 1) {

                    T[i] = 1;
                }
            }

            ii = L - 1;

            for (int i = 0; i <= L - 1; i++) {

                if (!T[i] && !G[U][i]) {

                    XOR[i] = 0;
                }
                else if (T[i] && !G[U][i]) {

                    XOR[i] = 1;
                }
                else if (!T[i] && G[U][i]) {

                    XOR[i] = 1;
                }
                else if (T[i] && G[U][i]) {

                    XOR[i] = 0;
                }

                if (XOR[i]) {

                    COMP[1] = COMP[1] + pow(nV, ii);
                }
                ii--;
            }

            for (int i = 0; i <= L - 1; i++) {

                std::cout << T[i];
            }
            std::cout << "\n";

            for (int i = 0; i <= L - 1; i++) {

                std::cout << G[U][i];
            }
            std::cout << "\n";

            for (int i = 0; i <= L - 1; i++) {

                std::cout << XOR[i];
            }
            std::cout << "\n";


            if (COMP[0] >= COMP[1] && COMP[1] <= LIM[F]) {

                COMP[1] = 0;
            }
            else if (COMP[0] < COMP[1] && COMP[1] <= LIM[F]) {

                COMP[0] = COMP[1];
                COMP[1] = 0;
            }
            std::cout << "\n";
        }
        else {

            break;
        }
    }

    S = COMP[0] + 0.5;

    for (int i = 0; i <= L - 1; i++) {

        XOR[i] = int(S * B[i]);

        XOR[i] = (XOR[i] - int(XOR[i] / nV) * nV) + 1;

        if (XOR[i] <= 1) {

            XOR[i] = 0;
        }
        else if (XOR[i] > 1) {

            XOR[i] = 1;
        }

        std::cout << XOR[i] << std::endl;
    }
    std::cout << "\n";

    std::cout << COMP[0] << std::endl;

    std::cout << "\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
}