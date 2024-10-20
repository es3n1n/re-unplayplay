using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;

namespace re_unplayplay;

public static class UnplayplayWrapper
{
    static UnplayplayWrapper()
    {
        // This forces the static constructor of NativeLibraryLoader to run
        NativeLibrary.SetDllImportResolver(Assembly.GetExecutingAssembly(), NativeLibraryLoader.ImportResolver);
    }


    [DllImport(NativeLibraryLoader.TargetLibraryName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    private static extern IntPtr decrypt_and_bind_key(
        byte[] encrypted_key,
        int key_length,
        string file_id,
        out int result_length
    );

    [DllImport(NativeLibraryLoader.TargetLibraryName, CallingConvention = CallingConvention.Cdecl)]
    private static extern void free_memory(IntPtr buffer);

    // Managed wrapper for decrypt_and_bind_key
    public static byte[] DecryptAndBindKey(byte[] encryptedKey, string fileId)
    {
        if (encryptedKey == null)
            throw new ArgumentNullException(nameof(encryptedKey));

        if (string.IsNullOrEmpty(fileId))
            throw new ArgumentException("File ID cannot be null or empty.", nameof(fileId));

        // Call the unmanaged function
        IntPtr resultPtr = decrypt_and_bind_key(encryptedKey, encryptedKey.Length, fileId, out int resultLength);

        // Check for failure
        if (resultPtr == IntPtr.Zero || resultLength == 0)
            throw new InvalidOperationException("decrypt_and_bind_key failed.");

        // Allocate a managed byte array to hold the result
        byte[] result = new byte[resultLength];

        // Copy data from unmanaged memory to managed array
        Marshal.Copy(resultPtr, result, 0, resultLength);

        // Free the unmanaged memory allocated by the C++ function
        free_memory(resultPtr);

        return result;
    }
}