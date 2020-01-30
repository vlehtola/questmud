long(str) {
write("You look the bushes closer and discover some hole where you might enter.\n");
return;
}
id(str) { return str == "bushes"; }
get(str) {
 if (str == "bushes") {
 write("You can't take the bushes.\n");
 return 0;
}
return 0;
}     
