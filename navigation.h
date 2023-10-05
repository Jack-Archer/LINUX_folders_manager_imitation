#pragma once

#include "dir.h"


class Navigation {
public:
    Navigation() = default;
    Navigation (Directory *dir);

    const Directory* getPtrFolder() const;

    const Directory* moveToDir(const Directory* ptr_on_dir);

private:
    const Directory *ptr_on_folder_{nullptr};
};

