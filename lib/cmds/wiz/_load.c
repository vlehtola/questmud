#define SIMUL	"/secure/simul_efun"

cmd_load(string str) { 
    if (!str) {
        write("Load what ?\n");
        return 1; 
    } 
    str = (string)SIMUL->valid_read(str, this_player());
    if (!str) { 
        write("Invalid file name.\n");
        return 1; 
    } 
    /* We just call a non existing function in the object, and that way
     * force it to be loaded. 
     */ 
    if(file_size(str) < 1 && file_size(str+".c") < 1) {
      write("No such file.\n");
      return 1;
    }
    call_other(str, "???"); 
    write("Loaded.\n"); 
    return 1; 
}   

