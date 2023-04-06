#include <vim.h>

static void my_mapping(void)
{
    // Do something when the mapping is invoked
}

void plugin_load(int fargs, char **args)
{
    // Define the mapping
    map("n", "<leader>m", "call MyMapping()", 0);

    // Define the function that will be called by the mapping
    function("MyMapping", my_mapping, 0);
}

