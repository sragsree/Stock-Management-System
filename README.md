# Stock Management System

Stock Management System is C++ application that provides a simple interface that allows authorized users (administrators) to do the following.

  - Add item to stock.
  - Display stock.
  - Search item in stock.
  - Update stock item information.
  - Delete stock item information.
  - Analysis of stock.


### Installation

This application requires a C++ IDE to run. The following sections gives you the instruction get this application up and running in a windows machine using MinGW.MinGW (short for "Minimalist GNU for Windows"), is a minimalist (i.e., small but fewer features compared with cygwin) development environment for native Microsoft Windows applications, in particular:

Goto MinGW mother site at http://www.mingw.org/ ⇒ Downloads ⇒ Installer ⇒ click on "mingw-get-inst" link to download the installer and then run it:
  - Set the installation directory. (Try to use a directory name without spaces, e.g., "d:\myproject\mingw". Try not to install under "Program Files" or "Desktop".);
  - GNU Bin MinGW Installation Manager, select "Installation" ⇒ "Update Catalogue" ⇒ Select all packages in "Basic Setup" ⇒ continue..
  - Setup environment variable PATH to include "<MINGW_HOME>/bin" where <MINGW_HOME> is the MinGW installed directory that you have chosen in the previous step.:
  - Verify the GCC installation by listing the version of gcc, g++ and gdb.


Install the dependencies and devDependencies and start the server.

```sh
$ gcc --version
$ g++ --version
$ gdb --version
```

### Usage
To make the application portable a .dat file is taken as database.

```sh
int main()
{
    std::fstream f;
    f.open("count.dat");
    if (!f.is_open())
    {
        //This runs when count.dat does not exist yet.
        std::cout << "Error opening file..." << std::endl;
        return -1;
    }   else std::cout << "File opened." << std::endl;
    f.close();
}
```

### Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request :D

License
----

**Free Software, Hell Yeah!**
