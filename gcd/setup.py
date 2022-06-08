from distutils.core import setup, Extension
 
def main():
	setup(name = "euclid",
    	version = "1.0.0",
        description = "Implementation of Euclid's algorithm in C",
        author = "Stefan Arseneau",
        author_email = "sarsene1@jhu.edu",
        ext_modules = [Extension("gcd", ["euclid.c"])])

if __name__ == "__main__":
	main()
