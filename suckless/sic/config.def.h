/* Host used when "-h" is not given */
#define DEFAULT_HOST "irc.libera.chat"

/* Port used when "-p" is not given */
#define DEFAULT_PORT "6667"

/* Timestamp format; see strftime(3). */
#define TIMESTAMP_FORMAT "%Y-%m-%d %R"

/* Command prefix character. In most IRC clients this is '/'. */
#define COMMAND_PREFIX_CHARACTER ':'

/* Parting message used when none is specified with ":l ..." command. */
#define DEFAULT_PARTING_MESSAGE "sic - 250 LOC are too much!"

/* default nick (if unspecified, use $USER) */
static const char *defaultuser = "sleepntsheep";

/* SASL in base64 */
/* nick\x00nick\x00password , encode it in base64 */
/* only used if -a arg is specified */
static const char *defaultauth = "";



