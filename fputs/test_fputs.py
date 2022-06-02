import fputs

print(fputs.__name__)
print(fputs.__doc__)

fputs.fputs("Writing python to a file with C", "write.txt")

with open("write.txt", "r") as f:
    print(f.read())
