using System.Reflection;
using System.Runtime.InteropServices;

namespace re_unplayplay;

public static class NativeLibraryLoader
{
    // Define the name of the library you're targeting
    public const string TargetLibraryName = "re-unplayplay-csharp.dll";
    
    /// <summary>
    /// Custom DLL import resolver to load native libraries from a specific path.
    /// </summary>
    /// <param name="libraryName">The name of the library to load.</param>
    /// <param name="assembly">The assembly requesting the library.</param>
    /// <param name="searchPath">The search path flags.</param>
    /// <returns>A handle to the loaded library, or IntPtr.Zero if not found.</returns>
    public static IntPtr ImportResolver(string libraryName, Assembly assembly, DllImportSearchPath? searchPath)
    {
        // Check if the requested library is the target library
        if (string.Equals(libraryName, TargetLibraryName, StringComparison.OrdinalIgnoreCase))
        {
            try
            {
                // Get the directory of the executing assembly
                string executingDir = Path.GetDirectoryName(assembly.Location);

                if (executingDir == null)
                {
                    throw new InvalidOperationException("Unable to determine the executing assembly's directory.");
                }

                // Construct the path to the build\Release directory
                // Adjust the relative path as needed based on your project structure
                string releaseDir = Path.GetFullPath(Path.Combine(executingDir, "..", "..", "..", "..", "..", "..", "build", "Release"));

                // Combine the release directory with the DLL name
                string libraryPath = Path.Combine(releaseDir, TargetLibraryName);

                // Verify that the DLL exists at the specified path
                if (!File.Exists(libraryPath))
                {
                    throw new DllNotFoundException($"The library '{TargetLibraryName}' was not found at path: {libraryPath}");
                }

                // Load and return the library handle
                return NativeLibrary.Load(libraryPath);
            }
            catch (Exception ex)
            {
                // Optionally, log the exception or handle it as needed
                Console.Error.WriteLine($"Error loading native library '{TargetLibraryName}': {ex.Message}");
                return IntPtr.Zero;
            }
        }

        // For any other library names, return IntPtr.Zero to indicate unresolved
        return IntPtr.Zero;
    }
}