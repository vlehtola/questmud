long(str) {
write("As you look the hole closer you discover some tunel where you could enter.\n");
return;
}
id(str) { return str == "hole"; }
get(str) {
 if (str == "bushes") {
 write("You can't take the hole.\n");
 return 0;
}
return 0;
} 
