#pragma once
 #include <iostream>

// ����� enum ��������
enum Permissions {
    PERMISSION_1 = 1 << 0, // 000001 -> 1
    PERMISSION_2 = 1 << 1, // 000010 -> 2
    PERMISSION_3 = 1 << 2, // 000100 -> 4
    PERMISSION_4 = 1 << 3, // 001000 -> 8
    PERMISSION_5 = 1 << 4, // 010000 -> 16
    PERMISSION_6 = 1 << 5, // 100000 -> 32
};

// ���� ���� ��������
int setPermissions(Permissions perm1, Permissions perm2 = Permissions(0), Permissions perm3 = Permissions(0), Permissions perm4 = Permissions(0), Permissions perm5 = Permissions(0), Permissions perm6 = Permissions(0)) {
    return perm1 | perm2 | perm3 | perm4 | perm5 | perm6;
}

// ���� ������ �� ��������
bool checkPermission(int permissions, Permissions permission) {
    return (permissions & permission) != 0;
}

void PermissionsExample() {
    // ����� ��������
    int permissions = setPermissions(PERMISSION_1, PERMISSION_3, PERMISSION_5);

    // ��� ������ ������� ����� ������
    std::cout << "������ ������� �������� �������: " << permissions << std::endl;

    // ������ �� ��� ���� �������� ������
    if (checkPermission(permissions, PERMISSION_1)) {
        std::cout << "����� 1 ����." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_2)) {
        std::cout << "����� 2 ����." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_3)) {
        std::cout << "����� 3 ����." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_4)) {
        std::cout << "����� 4 ����." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_5)) {
        std::cout << "����� 5 ����." << std::endl;
    }

    if (checkPermission(permissions, PERMISSION_6)) {
        std::cout << "����� 6 ����." << std::endl;
    }

 }
