#pragma once
 #include <iostream>

// ÊÚÑíİ enum ááÃĞæäÇÊ
enum enPermissions {
    PERMISSION_ListUsers = 1 << 0, // 000001 -> 1
    PERMISSION_Add = 1 << 1, // 000010 -> 2
    PERMISSION_Delete = 1 << 2, // 000100 -> 4
    PERMISSION_Update = 1 << 3, // 001000 -> 8
    PERMISSION_Find = 1 << 4, // 010000 -> 16
    PERMISSION_Transactions = 1 << 5, // 100000 -> 32
};

// ÏÇáÉ áæÖÚ ÇáÃĞæäÇÊ
int setPermissions(enPermissions perm1, enPermissions perm2 = enPermissions(0), enPermissions perm3 = enPermissions(0), enPermissions perm4 = enPermissions(0), enPermissions perm5 = enPermissions(0), enPermissions perm6 = enPermissions(0)) {
    return perm1 | perm2 | perm3 | perm4 | perm5 | perm6;
}

// ÏÇáÉ ááÊÍŞŞ ãä ÇáÃĞæäÇÊ
bool checkPermission(int permissions, enPermissions permission) {
    return (permissions & permission) != 0;
}
// ÏÇáÉ áÅÖÇİÉ ÃĞæäÇÊ ÌÏíÏÉ
int addPermissions(int permissions, enPermissions permToAdd) {
    return permissions | permToAdd;
}

// ÏÇáÉ áÅÒÇáÉ ÃĞæäÇÊ
int removePermissions(int permissions, enPermissions permToRemove) {
    return permissions & ~permToRemove;
}


void PermissionsExample() {
    // ÊÚííä ÇáÃĞæäÇÊ
    int permissions = setPermissions(PERMISSION_ListUsers, PERMISSION_Delete);

    // ÚÑÖ ÇáŞíãÉ ÇáÚÔÑíÉ ááÑŞã ÇáãÎÒä
    std::cout << "ÇáŞíãÉ ÇáÚÔÑíÉ ááÃĞæäÇÊ ÇáãÎÒäÉ: " << permissions << std::endl;

    // ÅÖÇİÉ ÅĞä ÌÏíÏ
    permissions = addPermissions(permissions, PERMISSION_Find);
    std::cout << "ÇáŞíãÉ ÇáÚÔÑíÉ ÈÚÏ ÅÖÇİÉ ÅĞä 5: " << permissions << std::endl;

    // ÅÒÇáÉ ÅĞä
    permissions = removePermissions(permissions, PERMISSION_Delete);
    std::cout << "ÇáŞíãÉ ÇáÚÔÑíÉ ÈÚÏ ÅÒÇáÉ ÅĞä 3: " << permissions << std::endl;

    // ÇáÊÍŞŞ ãä ÅĞä ãÍÏÏ ÈÇÓÊÎÏÇã ÇáÏÇáÉ
    if (checkPermission(permissions, PERMISSION_ListUsers)) {
        std::cout << "ÇáÅĞä 1 ãİÚá." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_Add)) {
        std::cout << "ÇáÅĞä 2 ãİÚá." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_Delete)) {
        std::cout << "ÇáÅĞä 3 ãİÚá." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_Update)) {
        std::cout << "ÇáÅĞä 4 ãİÚá." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_Find)) {
        std::cout << "ÇáÅĞä 5 ãİÚá." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_Transactions)) {
        std::cout << "ÇáÅĞä 6 ãİÚá." << std::endl;
    }
 }
