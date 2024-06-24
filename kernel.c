/* kernel.c */

/* Entry point of our kernel */
void kernel_main() {
    /* Display "Hello, World!" */
    const char *str = "Hello, World!";
    /* Call a function to write a string to the screen */
    print(str);
    
    /* Hang the CPU */
    for (;;);
}

/* Function to write a string to the screen */
void print(const char *str) {
    /* VGA text mode buffer starts from address 0xb8000 */
    unsigned short *video_memory = (unsigned short *)0xb8000;
    /* Attribute byte for our default color scheme */
    unsigned char color = 0x0F; // White text on black background
    
    /* Loop through each character of the string */
    for (int i = 0; str[i] != '\0'; ++i) {
        /* Calculate the index into the VGA buffer */
        unsigned short entry = (color << 8) | str[i];
        /* Write the character to the buffer */
        video_memory[i] = entry;
    }
}
