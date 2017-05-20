#include <iostream>
#include <algorithm>

using namespace std;

#define N 10000

enum line_t {
    start = 1,
    end = -1
};

typedef struct {
    int s, e;
}line_s;

typedef struct {
    int v;
    line_t t;
    
}note_s;

bool comp_for_max_overlap_length(line_s x, line_s y) {
    if (x.s < y.s) {
        return true;
    } else if (x.s == y.s && x.e > y.e) {
        return true;
    }
    return false;
}

bool comp_for_max_overlap_number(note_s x, note_s y) {
    if (x.v < y.v) {
        return true;
    } return false;
}

bool comp_for_max_not_overlap_number(line_s x, line_s y) {
    if (x.e < y.e) {
        return true;
    } else if (x.e == y.e && x.s > y.s) {
        return true;
    }
    return false;
}

int main(int argc, char** argv) {
    line_s line[] = {{.s=3, .e=5}, {.s=2, .e=4}, {.s=5, .e=9},
                     {.s=3, .e=7}, {.s=0, .e=3}, {.s=3, .e=8}};
    size_t n = sizeof(line)/sizeof(line[0]);
    
    for (int i = 0; i < n; i++) {
        printf("%d, %d\n", line[i].s, line[i].e);
    }
    printf("\n");

    note_s node[n << 1];
    for (int i = 0; i < n; i++) {
        node[i << 1].v = line[i].s;
        node[i << 1].t = start;
        node[(i << 1) + 1].v = line[i].e;
        node[(i << 1) + 1].t = end;
    }
    
    int max_gain = 0;
    int min_v = INT_MAX;
    int max_gain_buy, max_gain_sell, max_gain_buy_position, max_gain_sell_position;
    int gain_buy_position;
    for (int i = 0; i < n << 1; i++) {
        if (min_v > node[i].v) {
            min_v = node[i].v;
            gain_buy_position = i;
        }

        int diff = node[i].v - min_v;
        if(diff > max_gain) {
            max_gain = diff;
            max_gain_buy = min_v;
            max_gain_sell = node[i].v;
            max_gain_buy_position = gain_buy_position;
            max_gain_sell_position = i;
        }
        printf("min_v=%d\n", min_v);
    }
    printf("max_gain=%d value=(%d,%d) position=(%d,%d)\n\n", max_gain, max_gain_buy, max_gain_sell, max_gain_buy_position, max_gain_sell_position);

    sort(line, line + n, comp_for_max_overlap_length);

    int max_overlap_length = 0;
    int max_e = line[0].e;
    for (int i = 1; i < n; i++) {
        max_overlap_length = max(min(max_e, line[i].e) - line[i].s, max_overlap_length);
        max_e = max(line[i].e, max_e);
    }
    printf("max_overlap_length=%d\n\n", max_overlap_length);

    sort(node, node + n * 2, comp_for_max_overlap_number);

    int max_overlap_number = 0;
    int count;
    for (int i = 0; i < n << 1; i++) {
        count += node[i].t;
        max_overlap_number = max(count, max_overlap_number);
    }
    printf("max_overlap_number=%d\n\n", max_overlap_number);
    
    sort(line, line + n, comp_for_max_not_overlap_number);

    int max_not_overlap_number = 0;
    int prev_end = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (line[i].s >= prev_end) {
            max_not_overlap_number++;
            prev_end = line[i].e;
        }
    }
    printf("max_not_overlap_number=%d\n\n", max_not_overlap_number);

    return 0;
}
