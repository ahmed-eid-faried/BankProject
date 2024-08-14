#pragma once
#include <iostream>
//  ⁄—Ì› enum ··√–Ê‰« 
enum enPermissions {
	PERMISSION_ListUsers = 1 << 0, // 000001 -> 1
	PERMISSION_Add = 1 << 1, // 000010 -> 2
	PERMISSION_Delete = 1 << 2, // 000100 -> 4
	PERMISSION_Update = 1 << 3, // 001000 -> 8
	PERMISSION_Find = 1 << 4, // 010000 -> 16
	PERMISSION_Transactions = 1 << 5, // 100000 -> 32
};
struct sPermissions {
	enPermissions ListUsers= enPermissions(0);
	enPermissions Add = enPermissions(0);
	enPermissions Delete = enPermissions(0);
	enPermissions Update = enPermissions(0);
	enPermissions Find = enPermissions(0);
	enPermissions Transactions = enPermissions(0);
};



// œ«·… ·Ê÷⁄ «·√–Ê‰« 
int setPermissions(sPermissions Permissions) {
	return Permissions.ListUsers | Permissions.Add | Permissions.Delete | Permissions.Update | Permissions.Find | Permissions.Transactions;
}

// œ«·… ·· Õﬁﬁ „‰ «·√–Ê‰« 
bool checkPermission(int permissions, enPermissions permission) {
	return (permissions & permission) != 0;
}
// œ«·… ·≈÷«›… √–Ê‰«  ÃœÌœ…
int addPermissions(int permissions, enPermissions permToAdd) {
	return permissions | permToAdd;
}

// œ«·… ·≈“«·… √–Ê‰« 
int removePermissions(int permissions, enPermissions permToRemove) {
	return permissions & ~permToRemove;
}

int ReadPermissions() {
	sPermissions Permissions;
	Permissions.ListUsers = ReadBool("ARE YOU Permission FOR Show USER?") ? enPermissions::PERMISSION_ListUsers : enPermissions(0);
	Permissions.Add = ReadBool("ARE YOU Permission FOR Add USER?") ? enPermissions::PERMISSION_Add : enPermissions(0);
	Permissions.Delete = ReadBool("ARE YOU Permission FOR Delete USER?") ? enPermissions::PERMISSION_Delete : enPermissions(0);
	Permissions.Update = ReadBool("ARE YOU Permission FOR Update USER?") ? enPermissions::PERMISSION_Update : enPermissions(0);
	Permissions.Find = ReadBool("ARE YOU Permission FOR Find USER?") ? enPermissions::PERMISSION_Find : enPermissions(0);
	Permissions.Transactions = ReadBool("ARE YOU Permission FOR Transactions?") ? enPermissions::PERMISSION_ListUsers : enPermissions(0);
	return setPermissions(Permissions);
}
//
//void PermissionsExample() {
//
//	//  ⁄ÌÌ‰ «·√–Ê‰« 
//	sPermissions Permissions;
//	Permissions.ListUsers = enPermissions::PERMISSION_ListUsers;
//	Permissions.Delete = enPermissions::PERMISSION_Delete;
//	int permissions = setPermissions(Permissions);
//
//	// ⁄—÷ «·ﬁÌ„… «·⁄‘—Ì… ··—ﬁ„ «·„Œ“‰
//	std::cout << "«·ﬁÌ„… «·⁄‘—Ì… ··√–Ê‰«  «·„Œ“‰…: " << permissions << std::endl;
//
//	// ≈÷«›… ≈–‰ ÃœÌœ
//	permissions = addPermissions(permissions, PERMISSION_Find);
//	std::cout << "«·ﬁÌ„… «·⁄‘—Ì… »⁄œ ≈÷«›… ≈–‰ 5: " << permissions << std::endl;
//
//	// ≈“«·… ≈–‰
//	permissions = removePermissions(permissions, PERMISSION_Delete);
//	std::cout << "«·ﬁÌ„… «·⁄‘—Ì… »⁄œ ≈“«·… ≈–‰ 3: " << permissions << std::endl;
//
//	// «· Õﬁﬁ „‰ ≈–‰ „Õœœ »«” Œœ«„ «·œ«·…
//	if (checkPermission(permissions, PERMISSION_ListUsers)) {
//		std::cout << "«·≈–‰ 1 „›⁄·." << std::endl;
//	}
//
//	if (checkPermission(permissions, PERMISSION_Add)) {
//		std::cout << "«·≈–‰ 2 „›⁄·." << std::endl;
//	}
//
//	if (checkPermission(permissions, PERMISSION_Delete)) {
//		std::cout << "«·≈–‰ 3 „›⁄·." << std::endl;
//	}
//
//	if (checkPermission(permissions, PERMISSION_Update)) {
//		std::cout << "«·≈–‰ 4 „›⁄·." << std::endl;
//	}
//
//	if (checkPermission(permissions, PERMISSION_Find)) {
//		std::cout << "«·≈–‰ 5 „›⁄·." << std::endl;
//	}
//
//	if (checkPermission(permissions, PERMISSION_Transactions)) {
//		std::cout << "«·≈–‰ 6 „›⁄·." << std::endl;
//	}
//}
