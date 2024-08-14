#pragma once
 #include <iostream>

// ÊÚÑíİ enum ááÃĞæäÇÊ
enum Permissions {
    PERMISSION_1 = 1 << 0, // 000001 -> 1
    PERMISSION_2 = 1 << 1, // 000010 -> 2
    PERMISSION_3 = 1 << 2, // 000100 -> 4
    PERMISSION_4 = 1 << 3, // 001000 -> 8
    PERMISSION_5 = 1 << 4, // 010000 -> 16
    PERMISSION_6 = 1 << 5, // 100000 -> 32
};

// ÏÇáÉ áæÖÚ ÇáÃĞæäÇÊ
int setPermissions(Permissions perm1, Permissions perm2 = Permissions(0), Permissions perm3 = Permissions(0), Permissions perm4 = Permissions(0), Permissions perm5 = Permissions(0), Permissions perm6 = Permissions(0)) {
    return perm1 | perm2 | perm3 | perm4 | perm5 | perm6;
}

// ÏÇáÉ ááÊÍŞŞ ãä ÇáÃĞæäÇÊ
bool checkPermission(int permissions, Permissions permission) {
    return (permissions & permission) != 0;
}

void PermissionsExample() {
    // ÊÚííä ÇáÃĞæäÇÊ
    int permissions = setPermissions(PERMISSION_1, PERMISSION_3, PERMISSION_5);

    // ÚÑÖ ÇáŞíãÉ ÇáÚÔÑíÉ ááÑŞã ÇáãÎÒä
    std::cout << "ÇáŞíãÉ ÇáÚÔÑíÉ ááÃĞæäÇÊ ÇáãÎÒäÉ: " << permissions << std::endl;

    // ÇáÊÍŞŞ ãä ÅĞä ãÍÏÏ ÈÇÓÊÎÏÇã ÇáÏÇáÉ
    if (checkPermission(permissions, PERMISSION_1)) {
        std::cout << "ÇáÅĞä 1 ãİÚá." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_2)) {
        std::cout << "ÇáÅĞä 2 ãİÚá." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_3)) {
        std::cout << "ÇáÅĞä 3 ãİÚá." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_4)) {
        std::cout << "ÇáÅĞä 4 ãİÚá." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_5)) {
        std::cout << "ÇáÅĞä 5 ãİÚá." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_6)) {
        std::cout << "ÇáÅĞä 6 ãİÚá." << std::endl;
    }

 }
