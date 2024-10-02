
for line in ''''''.splitlines():
    line = line.split('//')[0].strip()
    fmt = '%llx' if 'uint64' in line or 'long long' in line else '%x'
    if 'char' in line or 'int8' in line:
        fmt = '%02x'
    name = line.split(' ')[-1].split(';')[0]
    type_ = line.split(';')[0]
    print('printf("' + type_ + ' = 0x' + fmt + ';\\n", static_cast<uint64_t>(' + name + '));')
