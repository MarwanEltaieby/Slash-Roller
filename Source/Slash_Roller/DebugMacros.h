#pragma once

#define DRAW_SPHERE(location) if (GetWorld()) DrawDebugSphere(GetWorld(), location, 100.f, 24, FColor::Blue, false, 30.f)
#define DRAW_SPHERE_SINGLE_FRAME(location) if (GetWorld()) DrawDebugSphere(GetWorld(), location, 100.f, 24, FColor::Blue, false, -1.f)
#define DRAW_LINE(startLine, endLine) if (GetWorld()) DrawDebugLine(GetWorld(), startLine, endLine, FColor::Green, false, 30.f, 0, 1.f)
#define DRAW_LINE_SINGLE_FRAME(startLine, endLine) if (GetWorld()) DrawDebugLine(GetWorld(), startLine, endLine, FColor::Green, false, -1.f, 0, 1.f)
#define DRAW_POINT(location) if (GetWorld()) DrawDebugPoint(GetWorld(), location, 15.f, FColor::Red, false, 30.f)
#define DRAW_POINT_SINGLE_FRAME(location) if (GetWorld()) DrawDebugPoint(GetWorld(), location, 15.f, FColor::Red, false, -1.f)
