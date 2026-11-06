// NoomiVita - a tiny physics bar-flipping game for PS Vita (vitasdk + vita2d)
// Verlet-physics stick figure on a high bar. Swing, let go, flip, stick the landing.
//
// Controls:
//   D-Pad / Left Stick  pump the swing (left / right)
//   Cross (hold)        tuck (spins faster)
//   Square (hold)       pike/hollow (sharper bend, slower spin)
//   R                   grab / release the bar
//   Triangle            reset
//   Start               quit

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <vita2d.h>
#include <math.h>
#include <stdlib.h>

#define W 960
#define H_SCREEN 544
#define GROUND 500.0f
#define BAR_X 480.0f
#define BAR_Y 150.0f
#define SUBSTEPS 4
#define DT (1.0f / 60.0f / SUBSTEPS)
#define GRAV 1400.0f
#define PI 3.14159265f

enum { HAND, SHOULDER, HEAD, HIP, FOOT, NP };

typedef struct { float x, y, px, py; } Pt;
typedef struct { int a, b; float rest, k; } Link;

static Pt p[NP];
static int gripped = 1;
static float tuck = 0.0f;   // 0 = straight, 1 = tucked
static float pike = 0.0f;
static float spin = 0.0f;   // accumulated rotation while airborne
static float lastAng = 0.0f;
static int airborne = 0, landed = 0, flips = 0, best = 0;
static const char *msg = "";
static int msgTimer
= 0;
    vita2d_free_pgf(font);
    vita2d_fini();
    sceKernelExitProcess(0);
    return 0;
}
