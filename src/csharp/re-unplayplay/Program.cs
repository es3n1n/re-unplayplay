using re_unplayplay;

var inputBytes = new byte[] { 226, 166, 189, 206, 215, 134, 205, 176, 94, 116, 247, 137, 240, 82, 85, 187 };
const string fileId = "6e08c09981b351459a139839e7eb33af85e84d10";
var result = UnplayplayWrapper.DecryptAndBindKey(inputBytes, fileId);
var expected = new byte[] { 167, 134, 103, 49, 251, 212, 55, 31, 246, 78, 196, 115, 79, 56, 47, 42 };
if (!result.SequenceEqual(expected))
{
     var exepctedHex = BitConverter.ToString(expected).Replace("-", "");
     var resultHex = BitConverter.ToString(result).Replace("-", "");
     throw new Exception($"Expected: {exepctedHex}, got: {resultHex}");
}

Console.WriteLine("Success!");