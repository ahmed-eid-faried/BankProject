#pragma once
#include <iostream>
#include "model.h"

sUser CurrentUser;
// ����� enum ��������
enum enPermissions {
	PERMISSION_ListUsers = 1 << 0, // 0000001 -> 1
	PERMISSION_Add = 1 << 1, // 0000010 -> 2
	PERMISSION_Delete = 1 << 2, // 0000100 -> 4
	PERMISSION_Update = 1 << 3, // 0001000 -> 8
	PERMISSION_Find = 1 << 4, // 0010000 -> 16
	PERMISSION_Transactions = 1 << 5, // 0100000 -> 32
	PERMISSION_MangeUsers = 1 << 6, // 1000000 -> 64
	PERMISSION_AllPermissions = (1 << 0 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5 | 1 << 6), // 1111111 -> 127
};

struct sPermissions {
	enPermissions ListUsers;
	enPermissions Add;
	enPermissions Delete;
	enPermissions Update;
	enPermissions FIND;
	enPermissions Transactions;
	enPermissions MangeUsers;
};

// ���� ���� ��������
int setPermissions(sPermissions Permissions) {
	return Permissions.ListUsers | Permissions.Add | Permissions.Delete | Permissions.Update | Permissions.FIND | Permissions.Transactions | Permissions.MangeUsers;
}

// ���� ������ �� ��������
bool checkPermission(enPermissions permission, int permissions = CurrentUser.Permissions) {
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

int ReadPermissions() {
	sPermissions Permissions;
	bool AllPermissions = ReadBool("ARE YOU GIVE All Permissions FOR This USER?");
	if (AllPermissions) {
		Permissions.ListUsers = enPermissions::PERMISSION_AllPermissions;
		Permissions.Add = enPermissions(0);
		Permissions.Delete = enPermissions(0);
		Permissions.Update = enPermissions(0);
		Permissions.FIND = enPermissions(0);
		Permissions.Transactions = enPermissions(0);
		Permissions.MangeUsers = enPermissions(0);
 	}
	else
	{
		Permissions.ListUsers = ReadBool("ARE YOU Permission FOR Show USER?") ? enPermissions::PERMISSION_ListUsers : enPermissions(0);
		Permissions.Add = ReadBool("ARE YOU Permission FOR Add USER?") ? enPermissions::PERMISSION_Add : enPermissions(0);
		Permissions.Delete = ReadBool("ARE YOU Permission FOR Delete USER?") ? enPermissions::PERMISSION_Delete : enPermissions(0);
		Permissions.Update = ReadBool("ARE YOU Permission FOR Update USER?") ? enPermissions::PERMISSION_Update : enPermissions(0);
		Permissions.FIND = ReadBool("ARE YOU Permission FOR Find USER?") ? enPermissions::PERMISSION_Find : enPermissions(0);
		Permissions.Transactions = ReadBool("ARE YOU Permission FOR Transactions?") ? enPermissions::PERMISSION_Transactions : enPermissions(0);
		Permissions.MangeUsers = ReadBool("ARE YOU Permission FOR MangeUsers?") ? enPermissions::PERMISSION_MangeUsers : enPermissions(0);

	}
	return setPermissions(Permissions);
}

void DeniedPermissions() {
	cout << "========================================================" << endl;
	cout << "========================================================" << endl;
	cout << "Access Denied" << endl;
	cout << "You don't Have Permiddion To Do This," << endl;
	cout << "Please Conact Your Admin." << endl;
	cout << "========================================================" << endl;
	cout << "========================================================" << endl;
}
//
//void PermissionsExample() {
//
//	// ����� ��������
//	sPermissions Permissions;
//	Permissions.ListUsers = enPermissions::PERMISSION_ListUsers;
//	Permissions.Delete = enPermissions::PERMISSION_Delete;
//	int permissions = setPermissions(Permissions);
//
//	// ��� ������ ������� ����� ������
//	std::cout << "������ ������� �������� �������: " << permissions << std::endl;
//
//	// ����� ��� ����
//	permissions = addPermissions(permissions, PERMISSION_Find);
//	std::cout << "������ ������� ��� ����� ��� 5: " << permissions << std::endl;
//
//	// ����� ���
//	permissions = removePermissions(permissions, PERMISSION_Delete);
//	std::cout << "������ ������� ��� ����� ��� 3: " << permissions << std::endl;
//
//	// ������ �� ��� ���� �������� ������
//	if (checkPermission(permissions, PERMISSION_ListUsers)) {
//		std::cout << "����� 1 ����." << std::endl;
//	}
//
//	if (checkPermission(permissions, PERMISSION_Add)) {
//		std::cout << "����� 2 ����." << std::endl;
//	}
//
//	if (checkPermission(permissions, PERMISSION_Delete)) {
//		std::cout << "����� 3 ����." << std::endl;
//	}
//
//	if (checkPermission(permissions, PERMISSION_Update)) {
//		std::cout << "����� 4 ����." << std::endl;
//	}
//
//	if (checkPermission(permissions, PERMISSION_Find)) {
//		std::cout << "����� 5 ����." << std::endl;
//	}
//
//	if (checkPermission(permissions, PERMISSION_Transactions)) {
//		std::cout << "����� 6 ����." << std::endl;
//	}
//}
