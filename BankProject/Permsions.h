#pragma once
 #include <iostream>

// ����� enum ��������
enum enPermissions {
    PERMISSION_ListUsers = 1 << 0, // 000001 -> 1
    PERMISSION_Add = 1 << 1, // 000010 -> 2
    PERMISSION_Delete = 1 << 2, // 000100 -> 4
    PERMISSION_Update = 1 << 3, // 001000 -> 8
    PERMISSION_Find = 1 << 4, // 010000 -> 16
    PERMISSION_Transactions = 1 << 5, // 100000 -> 32
};

// ���� ���� ��������
int setPermissions(enPermissions perm1, enPermissions perm2 = enPermissions(0), enPermissions perm3 = enPermissions(0), enPermissions perm4 = enPermissions(0), enPermissions perm5 = enPermissions(0), enPermissions perm6 = enPermissions(0)) {
    return perm1 | perm2 | perm3 | perm4 | perm5 | perm6;
}

// ���� ������ �� ��������
bool checkPermission(int permissions, enPermissions permission) {
    return (permissions & permission) != 0;
}
// ���� ������ ������ �����
int addPermissions(int permissions, enPermissions permToAdd) {
    return permissions | permToAdd;
}

// ���� ������ ������
int removePermissions(int permissions, enPermissions permToRemove) {
    return permissions & ~permToRemove;
}


void PermissionsExample() {
    // ����� ��������
    int permissions = setPermissions(PERMISSION_ListUsers, PERMISSION_Delete);

    // ��� ������ ������� ����� ������
    std::cout << "������ ������� �������� �������: " << permissions << std::endl;

    // ����� ��� ����
    permissions = addPermissions(permissions, PERMISSION_Find);
    std::cout << "������ ������� ��� ����� ��� 5: " << permissions << std::endl;

    // ����� ���
    permissions = removePermissions(permissions, PERMISSION_Delete);
    std::cout << "������ ������� ��� ����� ��� 3: " << permissions << std::endl;

    // ������ �� ��� ���� �������� ������
    if (checkPermission(permissions, PERMISSION_ListUsers)) {
        std::cout << "����� 1 ����." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_Add)) {
        std::cout << "����� 2 ����." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_Delete)) {
        std::cout << "����� 3 ����." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_Update)) {
        std::cout << "����� 4 ����." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_Find)) {
        std::cout << "����� 5 ����." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_Transactions)) {
        std::cout << "����� 6 ����." << std::endl;
    }
 }
