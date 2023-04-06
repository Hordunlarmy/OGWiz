#include <vim.h>

static void gpt_options(int count, char **args)
{
  // Open a new vertical split on the right-hand side
  ex("vertical botright split new");

  // Set the buffer name to GPT options
  ex("file GPT options");

  // Set buffer options
  ex("setlocal buftype=nofile");
  ex("setlocal noswapfile");
  ex("setlocal nomodifiable");

  // Define the GPT options
  char *options = "1. Ask GPT a question\n2. Review a code/write-up\n3. Rewrite a code/write-up\n";

  // Append the options to the buffer
  vim_append(0, -1, options, strlen(options));
}

void plugin_load(int fargs, char **args)
{
  // Define the command
  command_define("GPTOptions", "Open a new vertical buffer on the right-hand corner and list GPT options", gpt_options, 0, 0, 0);

  // Map the command to the `gs` key
  vim_define_key("n", "gs", ":GPTOptions<CR>", FALSE);
}

