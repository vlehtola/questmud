

init() {
   shadow(this_player(),1);         
}


self_destruct() {
destruct(this_object());
}

        

quit() {
write(":(\n");
return 1;
}

ld() {
write(":(\n");
return 1;
}

query_shadowed() {
return 1;
}                                        
