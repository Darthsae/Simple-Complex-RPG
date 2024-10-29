So, normal versioning exists, however, normal versioning is boring, so instead of doing that we are making our own versioning system.

#### Versioning Structure

The versioning system for **SimpleComplexRPG** follows a structured format of `xxxx.xxxx.xxxx.xxxx`, where each segment represents a specific aspect of the version. The version levels are classified into four categories: **alpha**, **beta**, **gamma**, and **delta**.

#### Version Format: `xxxx.xxxx.xxxx.xxxx`

- **xxxx.xxxx.xxxx.xxxx**: Represents a numerical value indicating the specific version.
- The segments are separated by periods (.) and signify different levels of development.
- Use all four characters, ie 0012, 0194, 1023.

#### Version Levels

1. **Alpha**
   - **Definition**: This level denotes an early version of the software that is still in development. Features may be incomplete, and the version may contain significant bugs.
   - **Example**: `xxxx.xxxx.xxxx.xxxx-α`
   - **Usage**: Versions in this level are meant for internal testing and are not recommended for general use.

2. **Beta**
   - **Definition**: This level indicates a version that is feature-complete but may still contain bugs. It is suitable for testing by users outside of the core development team.
   - **Example**: `xxxx.xxxx.xxxx.xxxx-β`
   - **Usage**: Versions in this level are intended for broader testing and feedback collection.

3. **Gamma**
   - **Definition**: This level represents a version that is stable and does not contain known bugs. It is safe for general use and introduces new features or improvements without breaking existing functionality.
   - **Example**: `xxxx.xxxx.xxxx.xxxx-γ`
   - **Usage**: Versions in this level are suitable for regular users and may include enhancements or optimizations.

4. **Delta**
   - **Definition**: This level represents a release that includes substantial changes or improvements that may not be backward compatible. It indicates a shift in functionality or performance.
   - **Example**: `xxxx.xxxx.xxxx.xxxx-δ`
   - **Usage**: Versions in this level are for users who are prepared for major updates and potential changes in existing features.

#### Incrementing Versions

- **Major Version (xxxx)**: Increment this value for major changes that introduce new features or make incompatible changes to the API.
- **Minor Version (xxxx)**: Increment this value for minor feature enhancements or significant improvements that are backward compatible.
- **Patch Version (xxxx)**: Increment this value for bug fixes or small improvements that do not affect the functionality.
- **Build Number (xxxx)**: Increment this value for each build, typically for internal tracking.

#### Conclusion

This versioning structure will help maintain clarity regarding the status of the software, allowing developers and users to understand the stability and readiness of different releases. Consistent use of this versioning system will aid in effective communication about updates and changes within the **SimpleComplexRPG** project.
